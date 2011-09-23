//---------------------------------------------------------------------------
#pragma once

#include "stdafx.h"
#include "Classes.h"
#include "FarUtil.h"

//---------------------------------------------------------------------------
bool ExceptionMessage(const std::exception *E, std::wstring & Message);
std::wstring LastSysErrorMessage();
TStrings *ExceptionToMoreMessages(const std::exception *E);
//---------------------------------------------------------------------------
enum TOnceDoneOperation { odoIdle, odoDisconnect, odoShutDown };
//---------------------------------------------------------------------------
class ExtException : public std::exception
{
  typedef std::exception parent;
public:
  ExtException(const std::exception *E);
  ExtException(const std::exception *E, std::wstring Msg);
  // "copy the std::exception", just append message to the end
  ExtException(std::wstring Msg);
  ExtException(std::wstring Msg, const std::exception *E);
  ExtException(std::wstring Msg, std::wstring MoreMessages, std::wstring HelpKeyword = L"");
  ExtException(std::wstring Msg, TStrings *MoreMessages, bool Own);
  virtual ~ExtException(void);
  TStrings *GetMoreMessages() const { return FMoreMessages; }
  std::wstring GetHelpKeyword() const { return FHelpKeyword; }

  // inline ExtException(const std::wstring Msg, const TVarRec *Args, const int Args_Size) : Sysutils::exception(Msg, Args, Args_Size) {}
  // inline ExtException(int Ident, const TVarRec *Args, const int Args_Size)/*overload */ : Sysutils::exception(Ident, Args, Args_Size) {}
  ExtException(const std::wstring Msg, int AHelpContext);
  // inline ExtException(const std::wstring Msg, const TVarRec *Args, const int Args_Size, int AHelpContext) : Sysutils::exception(Msg, Args, Args_Size, AHelpContext) {}
  // inline ExtException(int Ident, int AHelpContext)/*overload */ : std::exception(Ident, AHelpContext) {}
  // inline ExtException(PResStringRec ResStringRec, const TVarRec *Args, const int Args_Size, int AHelpContext)/*overload */ : Sysutils::exception(ResStringRec, Args, Args_Size, AHelpContext) {}
  const std::wstring GetMessage() const { return FMessage; }
  void SetMessage(const std::wstring value) { FMessage = value; }
protected:
  void AddMoreMessages(const std::exception *E);

private:
  TStrings *FMoreMessages;
  std::wstring FHelpKeyword;
  std::wstring FMessage;
};
//---------------------------------------------------------------------------
#define DERIVE_EXT_EXCEPTION(NAME, BASE) \
  class NAME : public BASE \
  { \
    typedef BASE parent; \
  public: \
    inline NAME(const std::exception *E, std::wstring Msg) : parent(E, Msg) {} \
    inline virtual ~NAME(void) {} \
    inline NAME(const std::wstring Msg, int AHelpContext) : parent(Msg, AHelpContext) {} \
  };

    // inline NAME(const std::exception *E, int Ident) : parent(E, Ident) {} \
    // inline NAME(const std::wstring Msg, const TVarRec *Args, const int Args_Size) : parent(Msg, Args, Args_Size) {} \
    // inline NAME(int Ident, const TVarRec *Args, const int Args_Size) : parent(Ident, Args, Args_Size) {} \
    // inline NAME(const std::wstring Msg, const TVarRec *Args, const int Args_Size, int AHelpContext) : parent(Msg, Args, Args_Size, AHelpContext) {} \
    // inline NAME(PResStringRec ResStringRec, const TVarRec *Args, const int Args_Size, int AHelpContext) : parent(ResStringRec, Args, Args_Size, AHelpContext) {} \
    // inline NAME(int Ident, int AHelpContext) : parent(Ident, AHelpContext) {} \

//---------------------------------------------------------------------------
DERIVE_EXT_EXCEPTION(ESsh, ExtException);
DERIVE_EXT_EXCEPTION(ETerminal, ExtException);
DERIVE_EXT_EXCEPTION(ECommand, ExtException);
DERIVE_EXT_EXCEPTION(EScp, ExtException); // SCP protocol fatal error (non-fatal in application context)
DERIVE_EXT_EXCEPTION(EScpSkipFile, ExtException);
DERIVE_EXT_EXCEPTION(EScpFileSkipped, EScpSkipFile);
//---------------------------------------------------------------------------
class EOSExtException : public ExtException
{
  typedef ExtException parent;
public:
  EOSExtException();
  EOSExtException(std::wstring Msg);
};
//---------------------------------------------------------------------------
class EFatal : public ExtException
{
  typedef ExtException parent;
public:
  // fatal errors are always copied, new message is only appended
  inline EFatal(const std::exception *E, std::wstring Msg) : ExtException(Msg, E) {}
};
//---------------------------------------------------------------------------
#define DERIVE_FATAL_EXCEPTION(NAME, BASE) \
  class NAME : public BASE \
  { \
    typedef BASE parent; \
  public: \
    inline NAME(const std::exception *E, std::wstring Msg) : parent(E, Msg) {} \
  };
//---------------------------------------------------------------------------
DERIVE_FATAL_EXCEPTION(ESshFatal, EFatal);
//---------------------------------------------------------------------------
// std::exception that closes application, but displayes info message (not error message)
// = close on completionclass ESshTerminate : public EFatal
class ESshTerminate : public EFatal
{
  typedef EFatal parent;
public:
  inline ESshTerminate(const std::exception *E, std::wstring Msg, TOnceDoneOperation AOperation) :
    parent(E, Msg),
    Operation(AOperation)
  {}

  TOnceDoneOperation Operation;
};
//---------------------------------------------------------------------------
