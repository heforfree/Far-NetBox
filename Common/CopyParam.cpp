//---------------------------------------------------------------------------
#include "stdafx.h"

#include "Common.h"
#include "CopyParam.h"
#include "HierarchicalStorage.h"
#include "TextsCore.h"
#include "FarUtil.h"
//---------------------------------------------------------------------------
TCopyParamType::TCopyParamType()
{
  Default();
}
//---------------------------------------------------------------------------
TCopyParamType::TCopyParamType(const TCopyParamType & Source)
{
  Assign(&Source);
}
//---------------------------------------------------------------------------
TCopyParamType::~TCopyParamType()
{
}
//---------------------------------------------------------------------------
void TCopyParamType::Default()
{
  // when changing defaults, make sure GetInfoStr() can handle it
  SetFileNameCase(ncNoChange);
  SetPreserveReadOnly(false);
  SetPreserveTime(true);
  GetRights().SetNumber(TRights::rfDefault);
  SetPreserveRights(false); // Was true until #106
  SetIgnorePermErrors(false);
  FAsciiFileMask.SetMasks(L"*.*html; *.htm; *.txt; *.php; *.php3; *.cgi; *.c; *.cpp; *.h; *.pas; "
    L"*.bas; *.tex; *.pl; *.js; .htaccess; *.xtml; *.css; *.cfg; *.ini; *.sh; *.xml");
  SetTransferMode(tmAutomatic);
  SetAddXToDirectories(true);
  SetResumeSupport(rsSmart);
  SetResumeThreshold(100 * 1024); // (100 KiB)
  SetInvalidCharsReplacement(TokenReplacement);
  SetLocalInvalidChars(L"/\\:*?\"<>|");
  SetCalculateSize(true);
  SetFileMask(L"*.*");
  GetExcludeFileMask().SetMasks(L"");
  SetNegativeExclude(false);
  SetClearArchive(false);
  SetCPSLimit(0);
}
//---------------------------------------------------------------------------
std::wstring TCopyParamType::GetInfoStr(std::wstring Separator, int Options) const
{
  TCopyParamType Defaults;
  std::wstring Result;

  bool SomeAttrExcluded = false;
  #define ADD(STR, EXCEPT) \
    if (FLAGCLEAR(Options, EXCEPT)) \
    { \
      Result += (Result.empty() ? std::wstring() : Separator) + (STR); \
    } \
    else \
    { \
      SomeAttrExcluded = true; \
    }

  if ((GetTransferMode() != Defaults.GetTransferMode()) ||
      ((GetTransferMode() == tmAutomatic) && !(GetAsciiFileMask() == Defaults.GetAsciiFileMask())))
  {
    std::wstring S = ::FORMAT(LoadStrPart(COPY_INFO_TRANSFER_TYPE, 1).c_str(),
      LoadStrPart(COPY_INFO_TRANSFER_TYPE, GetTransferMode() + 2).c_str());
    if (GetTransferMode() == tmAutomatic)
    {
      S = ::FORMAT(S.c_str(), GetAsciiFileMask().GetMasks().c_str());
    }
    ADD(S, cpaExcludeMaskOnly | cpaNoTransferMode);
  }

  if (GetFileNameCase() != Defaults.GetFileNameCase())
  {
    ADD(FORMAT(LoadStrPart(COPY_INFO_FILENAME, 1).c_str(),
      LoadStrPart(COPY_INFO_FILENAME, GetFileNameCase() + 2).c_str()),
      cpaExcludeMaskOnly);
  }

  if ((GetInvalidCharsReplacement() == NoReplacement) !=
        (Defaults.GetInvalidCharsReplacement() == NoReplacement))
  {
    assert(GetInvalidCharsReplacement() == NoReplacement);
    if (GetInvalidCharsReplacement() == NoReplacement)
    {
      ADD(LoadStr(COPY_INFO_DONT_REPLACE_INV_CHARS).c_str(), cpaExcludeMaskOnly);
    }
  }

  if ((GetPreserveRights() != Defaults.GetPreserveRights()) ||
      (GetPreserveRights() &&
       ((GetRights() != Defaults.GetRights()) || (GetAddXToDirectories() != Defaults.GetAddXToDirectories()))))
  {
    assert(GetPreserveRights());

    if (GetPreserveRights())
    {
      std::wstring RightsStr = GetRights().GetText();
      if (GetAddXToDirectories())
      {
        RightsStr += L", " + LoadStr(COPY_INFO_ADD_X_TO_DIRS);
      }
      ADD(FORMAT(LoadStr(COPY_INFO_PERMISSIONS).c_str(), RightsStr.c_str()),
        cpaExcludeMaskOnly | cpaNoRights);
    }
  }

  if (GetPreserveTime() != Defaults.GetPreserveTime())
  {
    ADD(LoadStr(GetPreserveTime() ? COPY_INFO_TIMESTAMP : COPY_INFO_DONT_PRESERVE_TIME).c_str(),
      cpaExcludeMaskOnly | cpaNoPreserveTime);
  }

  if ((GetPreserveRights() || GetPreserveTime()) &&
      (GetIgnorePermErrors() != Defaults.GetIgnorePermErrors()))
  {
    assert(GetIgnorePermErrors());

    if (GetIgnorePermErrors())
    {
      ADD(LoadStr(COPY_INFO_IGNORE_PERM_ERRORS).c_str(),
        cpaExcludeMaskOnly | cpaNoIgnorePermErrors);
    }
  }

  if (GetPreserveReadOnly() != Defaults.GetPreserveReadOnly())
  {
    assert(GetPreserveReadOnly());
    if (GetPreserveReadOnly())
    {
      ADD(LoadStr(COPY_INFO_PRESERVE_READONLY).c_str(),
        cpaExcludeMaskOnly | cpaNoPreserveReadOnly);
    }
  }

  if (GetCalculateSize() != Defaults.GetCalculateSize())
  {
    assert(!GetCalculateSize());
    if (!GetCalculateSize())
    {
      ADD(LoadStr(COPY_INFO_DONT_CALCULATE_SIZE).c_str(), cpaExcludeMaskOnly);
    }
  }

  if (GetClearArchive() != Defaults.GetClearArchive())
  {
    assert(GetClearArchive());
    if (GetClearArchive())
    {
      ADD(LoadStr(COPY_INFO_CLEAR_ARCHIVE),
        cpaExcludeMaskOnly | cpaNoClearArchive);
    }
  }

  if (((GetNegativeExclude() != Defaults.GetNegativeExclude()) && !(GetExcludeFileMask() == L"")) ||
      !(GetExcludeFileMask() == Defaults.GetExcludeFileMask()))
  {
    ADD(FORMAT(LoadStr(GetNegativeExclude() ? COPY_INFO_INCLUDE_MASK : COPY_INFO_EXCLUDE_MASK).c_str(),
      (GetExcludeFileMask().GetMasks())),
      cpaNoExcludeMask);
  }

  if (GetCPSLimit() > 0)
  {
    // FIXME ADD(FMTLOAD(COPY_INFO_CPS_LIMIT, (int(GetCPSLimit() / 1024))).c_str(), cpaExcludeMaskOnly);
    ADD(L"", cpaExcludeMaskOnly);
  }

  if (SomeAttrExcluded)
  {
    Result += (Result.empty() ? std::wstring() : Separator) +
      FORMAT(LoadStrPart(COPY_INFO_NOT_USABLE, 1).c_str(),
        (LoadStrPart(COPY_INFO_NOT_USABLE, (Result.empty() ? 3 : 2)).c_str()));
  }
  else if (Result.empty())
  {
    Result = LoadStr(COPY_INFO_DEFAULT);
  }
  #undef ADD

  return Result;
}
//---------------------------------------------------------------------------
void TCopyParamType::Assign(const TCopyParamType * Source)
{
  assert(Source != NULL);
  #define COPY(Prop) Set##Prop(Source->Get##Prop())
  COPY(FileNameCase);
  COPY(PreserveReadOnly);
  COPY(PreserveTime);
  COPY(Rights);
  COPY(AsciiFileMask);
  COPY(TransferMode);
  COPY(AddXToDirectories);
  COPY(PreserveRights);
  COPY(IgnorePermErrors);
  COPY(ResumeSupport);
  COPY(ResumeThreshold);
  COPY(InvalidCharsReplacement);
  COPY(LocalInvalidChars);
  COPY(CalculateSize);
  COPY(FileMask);
  COPY(ExcludeFileMask);
  COPY(NegativeExclude);
  COPY(ClearArchive);
  COPY(CPSLimit);
  #undef COPY
}
//---------------------------------------------------------------------------
TCopyParamType & TCopyParamType::operator =(const TCopyParamType & rhp)
{
  Assign(&rhp);
  return *this;
}
//---------------------------------------------------------------------------
void TCopyParamType::SetLocalInvalidChars(std::wstring value)
{
  if (value != GetLocalInvalidChars())
  {
    FLocalInvalidChars = value;
    FTokenizibleChars = FLocalInvalidChars + TokenPrefix;
  }
}
//---------------------------------------------------------------------------
bool TCopyParamType::GetReplaceInvalidChars() const
{
  return (GetInvalidCharsReplacement() != NoReplacement);
}
//---------------------------------------------------------------------------
void TCopyParamType::SetReplaceInvalidChars(bool value)
{
  if (GetReplaceInvalidChars() != value)
  {
    SetInvalidCharsReplacement((value ? TokenReplacement : NoReplacement));
  }
}
//---------------------------------------------------------------------------
wchar_t * TCopyParamType::ReplaceChar(std::wstring & FileName, wchar_t * InvalidChar) const
{
  int Index = InvalidChar - FileName.c_str() + 1;
  if (false) // FIXME FileName.GetByteType(Index) == mbSingleByte)
  {
    if (GetInvalidCharsReplacement() == TokenReplacement)
    {
      FileName.insert(Index + 1, CharToHex(FileName[Index]));
      FileName[Index] = TokenPrefix;
      InvalidChar = (wchar_t *)FileName.c_str() + Index + 2;
    }
    else
    {
      FileName[Index] = GetInvalidCharsReplacement();
      InvalidChar++;
    }
  }
  else
  {
    InvalidChar++;
  }
  return InvalidChar;
}
//---------------------------------------------------------------------------
std::wstring TCopyParamType::ValidLocalFileName(std::wstring FileName) const
{
  if (GetInvalidCharsReplacement() != NoReplacement)
  {
    bool ATokenReplacement = (GetInvalidCharsReplacement() == TokenReplacement);
    const wchar_t * Chars =
      (ATokenReplacement ? FTokenizibleChars : GetLocalInvalidChars()).c_str();
    wchar_t * InvalidChar = (wchar_t *)FileName.c_str();
    while ((InvalidChar = wcspbrk(InvalidChar, Chars)) != NULL)
    {
      int Pos = (InvalidChar - FileName.c_str() + 1);
      char Char;
      if ((GetInvalidCharsReplacement() == TokenReplacement) &&
          (*InvalidChar == TokenPrefix) &&
          (((FileName.size() - Pos) <= 1) ||
           (((Char = HexToChar(FileName.substr(Pos + 1, 2))) == '\0') ||
            (FTokenizibleChars.find_first_of(Char) == 0))))
      {
        InvalidChar++;
      }
      else
      {
        InvalidChar = ReplaceChar(FileName, InvalidChar);
      }
    }

    // Windows trim trailing space or dot, hence we must encode it to preserve it
    if (!FileName.empty() &&
        ((FileName[FileName.size()] == ' ') ||
         (FileName[FileName.size()] == '.')))
    {
      ReplaceChar(FileName, (wchar_t *)FileName.c_str() + FileName.size() - 1);
    }

    if (IsReservedName(FileName))
    {
      int P = FileName.find_first_of(L".");
      if (P == 0)
      {
        P = FileName.size() + 1;
      }
      FileName.insert(P, L"%00");
    }
  }
  return FileName;
}
//---------------------------------------------------------------------------
std::wstring TCopyParamType::RestoreChars(std::wstring FileName) const
{
  if (GetInvalidCharsReplacement() == TokenReplacement)
  {
    wchar_t * InvalidChar = (wchar_t *)FileName.c_str();
    while ((InvalidChar = wcschr(InvalidChar, TokenPrefix)) != NULL)
    {
      int Index = InvalidChar - FileName.c_str() + 1;
      if ((FileName.size() >= Index + 2) &&
          false // FIXME (FileName.ByteType(Index) == mbSingleByte) &&
          // (FileName.ByteType(Index + 1) == mbSingleByte) &&
          // (FileName.ByteType(Index + 2) == mbSingleByte)
          )
      {
        std::wstring Hex = FileName.substr(Index + 1, 2);
        char Char = HexToChar(Hex);
        if ((Char != '\0') &&
            ((FTokenizibleChars.find_first_of(Char) > 0) ||
             (((Char == ' ') || (Char == '.')) && (Index == FileName.size() - 2))))
        {
          FileName[Index] = Char;
          FileName.erase(Index + 1, 2);
          InvalidChar = (wchar_t *)FileName.c_str() + Index;
        }
        else if ((Hex == L"00") &&
                 ((Index == FileName.size() - 2) || (FileName[Index + 3] == '.')) &&
                 IsReservedName(FileName.substr(1, Index - 1) + FileName.substr(Index + 3, FileName.size() - Index - 3 + 1)))
        {
          FileName.erase(Index, 3);
          InvalidChar = (wchar_t *)FileName.c_str() + Index - 1;
        }
        else
        {
          InvalidChar++;
        }
      }
      else
      {
        InvalidChar++;
      }
    }
  }
  return FileName;
}
//---------------------------------------------------------------------------
std::wstring TCopyParamType::ValidLocalPath(std::wstring Path) const
{
  std::wstring Result;
  while (!Path.empty())
  {
    if (!Result.empty())
    {
      Result += L"\\";
    }
    Result += ValidLocalFileName(CutToChar(Path, '\\', false));
  }
  return Result;
}
//---------------------------------------------------------------------------
// not used yet
std::wstring TCopyParamType::Untokenize(std::wstring FileName)
{
  wchar_t * Token;
  std::wstring Result = FileName;
  while ((Token = AnsiStrScan(Result.c_str(), TokenPrefix)) != NULL)
  {
    int Index = Token - Result.c_str() + 1;
    if (Index > Result.size() - 2)
    {
      Result = FileName;
      break;
    }
    else
    {
      wchar_t Ch = (wchar_t)HexToInt(Result.substr(Index + 1, 2), -1);
      if (Ch == '\0')
      {
        Result = FileName;
        break;
      }
      else
      {
        Result[Index] = Ch;
        Result.erase(Index + 1, 2);
      }
    }
  }
  return Result;
}
//---------------------------------------------------------------------------
std::wstring TCopyParamType::ChangeFileName(std::wstring FileName,
  TOperationSide Side, bool FirstLevel) const
{
  if (FirstLevel)
  {
    FileName = MaskFileName(FileName, GetFileMask());
  }
  switch (GetFileNameCase()) {
    case ncUpperCase: FileName = UpperCase(FileName); break;
    case ncLowerCase: FileName = LowerCase(FileName); break;
    case ncFirstUpperCase: FileName = UpperCase(FileName.substr(1, 1)) +
      FileName.substr(2, LowerCase(FileName.size()-1)); break;
    case ncLowerCaseShort:
      if ((FileName.size() <= 12) && (FileName.find_first_of(L".") <= 9) &&
          (FileName == UpperCase(FileName)))
      {
        FileName = LowerCase(FileName);
      }
      break;
    case ncNoChange:
    default:
      /*nothing*/
      break;
  }
  if (Side == osRemote)
  {
    FileName = ValidLocalFileName(FileName);
  }
  else
  {
    FileName = RestoreChars(FileName);
  }
  return FileName;
}
//---------------------------------------------------------------------------
bool TCopyParamType::UseAsciiTransfer(std::wstring FileName,
  TOperationSide Side, const TFileMasks::TParams & Params) const
{
  switch (TransferMode) {
    case tmBinary: return false;
    case tmAscii: return true;
    case tmAutomatic: return AsciiFileMask.Matches(FileName, (Side == osLocal),
      false, &Params);
    default: assert(false); return false;
  }
}
//---------------------------------------------------------------------------
TRights TCopyParamType::RemoteFileRights(int Attrs) const
{
  TRights R = Rights;
  if ((Attrs & faDirectory) && AddXToDirectories)
    R.AddExecute();
  return R;
}
//---------------------------------------------------------------------------
std::wstring TCopyParamType::GetLogStr() const
{
  char CaseC[] = "NULFS";
  char ModeC[] = "BAM";
  char ResumeC[] = "YSN";
  return FORMAT(
    "  PrTime: %s; PrRO: %s; Rght: %s; PrR: %s (%s); FnCs: %s; RIC: %s; "
      "Resume: %s (%d); CalcS: %s; Mask: %s\n"
    "  TM: %s; ClAr: %s; CPS: %u; ExclM(%s): %s\n"
    "  AscM: %s\n",
    (BooleanToEngStr(PreserveTime),
     BooleanToEngStr(GetPreserveReadOnly()),
     Rights.Text,
     BooleanToEngStr(PreserveRights),
     BooleanToEngStr(IgnorePermErrors),
     CaseC[FileNameCase],
     CharToHex(InvalidCharsReplacement),
     ResumeC[ResumeSupport],
     (int)ResumeThreshold,
     BooleanToEngStr(GetCalculateSize()),
     FileMask,
     ModeC[TransferMode],
     BooleanToEngStr(GetClearArchive()),
     int(CPSLimit),
     BooleanToEngStr(GetNegativeExclude()),
     GetExcludeFileMask().Masks,
     AsciiFileMask.Masks));
}
//---------------------------------------------------------------------------
int TCopyParamType::LocalFileAttrs(const TRights & Rights) const
{
  int Result = 0;
  if (GetPreserveReadOnly() && !Rights.Right[TRights::rrUserWrite])
  {
    Result |= faReadOnly;
  }
  return Result;
}
//---------------------------------------------------------------------------
bool TCopyParamType::AllowResume(__int64 Size) const
{
  switch (ResumeSupport) {
    case rsOn: return true;
    case rsOff: return false;
    case rsSmart: return (Size >= ResumeThreshold);
    default: assert(false); return false;
  }
}
//---------------------------------------------------------------------------
bool TCopyParamType::AllowAnyTransfer() const
{
  return GetExcludeFileMask().Masks.empty();
}
//---------------------------------------------------------------------------
bool TCopyParamType::AllowTransfer(std::wstring FileName,
  TOperationSide Side, bool Directory, const TFileMasks::TParams & Params) const
{
  bool Result = true;
  if (!GetExcludeFileMask().Masks.empty())
  {
    Result = (GetExcludeFileMask().Matches(FileName, (Side == osLocal),
      Directory, &Params) == GetNegativeExclude());
  }
  return Result;
}
//---------------------------------------------------------------------------
void TCopyParamType::Load(THierarchicalStorage * Storage)
{
  AddXToDirectories = Storage->ReadBool("AddXToDirectories", AddXToDirectories);
  AsciiFileMask.Masks = Storage->ReadString("Masks", AsciiFileMask.Masks);
  FileNameCase = (TFileNameCase)Storage->ReadInteger("FileNameCase", FileNameCase);
  GetPreserveReadOnly() = Storage->ReadBool("GetPreserveReadOnly()", GetPreserveReadOnly());
  PreserveTime = Storage->ReadBool("PreserveTime", PreserveTime);
  PreserveRights = Storage->ReadBool("PreserveRights", PreserveRights);
  IgnorePermErrors = Storage->ReadBool("IgnorePermErrors", IgnorePermErrors);
  Rights.Text = Storage->ReadString("Text", Rights.Text);
  TransferMode = (TTransferMode)Storage->ReadInteger("TransferMode", TransferMode);
  ResumeSupport = (TResumeSupport)Storage->ReadInteger("ResumeSupport", ResumeSupport);
  ResumeThreshold = Storage->ReadInt64("ResumeThreshold", ResumeThreshold);
  InvalidCharsReplacement = (char)Storage->ReadInteger("ReplaceInvalidChars",
    (unsigned char)InvalidCharsReplacement);
  LocalInvalidChars = Storage->ReadString("LocalInvalidChars", LocalInvalidChars);
  GetCalculateSize() = Storage->ReadBool("GetCalculateSize()", GetCalculateSize());
  GetExcludeFileMask().Masks = Storage->ReadString("GetExcludeFileMask()", GetExcludeFileMask().Masks);
  GetNegativeExclude() = Storage->ReadBool("GetNegativeExclude()", GetNegativeExclude());
  GetClearArchive() = Storage->ReadBool("GetClearArchive()", GetClearArchive());
  CPSLimit = Storage->ReadInteger("CPSLimit", CPSLimit);
}
//---------------------------------------------------------------------------
void TCopyParamType::Save(THierarchicalStorage * Storage) const
{
  Storage->WriteBool("AddXToDirectories", AddXToDirectories);
  Storage->WriteString("Masks", AsciiFileMask.Masks);
  Storage->WriteInteger("FileNameCase", FileNameCase);
  Storage->WriteBool("GetPreserveReadOnly()", GetPreserveReadOnly());
  Storage->WriteBool("PreserveTime", PreserveTime);
  Storage->WriteBool("PreserveRights", PreserveRights);
  Storage->WriteBool("IgnorePermErrors", IgnorePermErrors);
  Storage->WriteString("Text", Rights.Text);
  Storage->WriteInteger("TransferMode", TransferMode);
  Storage->WriteInteger("ResumeSupport", ResumeSupport);
  Storage->WriteInt64("ResumeThreshold", ResumeThreshold);
  Storage->WriteInteger("ReplaceInvalidChars", (unsigned char)InvalidCharsReplacement);
  Storage->WriteString("LocalInvalidChars", LocalInvalidChars);
  Storage->WriteBool("GetCalculateSize()", GetCalculateSize());
  Storage->WriteString("GetExcludeFileMask()", GetExcludeFileMask().Masks);
  Storage->WriteBool("GetNegativeExclude()", GetNegativeExclude());
  Storage->WriteBool("GetClearArchive()", GetClearArchive());
  Storage->WriteInteger("CPSLimit", CPSLimit);
}
//---------------------------------------------------------------------------
#define C(Property) (Property == rhp.Property)
bool TCopyParamType::operator==(const TCopyParamType & rhp) const
{
  return
    C(AddXToDirectories) &&
    C(AsciiFileMask) &&
    C(FileNameCase) &&
    C(GetPreserveReadOnly()) &&
    C(PreserveTime) &&
    C(PreserveRights) &&
    C(IgnorePermErrors) &&
    C(Rights) &&
    C(TransferMode) &&
    C(ResumeSupport) &&
    C(ResumeThreshold) &&
    C(InvalidCharsReplacement) &&
    C(LocalInvalidChars) &&
    C(GetCalculateSize()) &&
    C(GetExcludeFileMask()) &&
    C(GetNegativeExclude()) &&
    C(GetClearArchive()) &&
    C(CPSLimit) &&
    true;
}
#undef C
//---------------------------------------------------------------------------
unsigned long GetSpeedLimit(const std::wstring & Text)
{
  unsigned long Speed;
  if (AnsiSameText(Text, LoadStr(SPEED_UNLIMITED)))
  {
    Speed = 0;
  }
  else
  {
    int SSpeed;
    if (!TryStrToInt(Text, SSpeed) ||
        (SSpeed < 0))
    {
      throw exception(FMTLOAD(SPEED_INVALID, (Text)));
    }
    Speed = SSpeed;
  }
  return Speed * 1024;
}
//---------------------------------------------------------------------------
std::wstring SetSpeedLimit(unsigned long Limit)
{
  std::wstring Text;
  if (Limit == 0)
  {
    Text = LoadStr(SPEED_UNLIMITED);
  }
  else
  {
    Text = IntToStr(Limit / 1024);
  }
  return Text;
}
