/* when building libcurl itself */
#undef BUILDING_LIBCURL

/* Location of default ca bundle */
#undef CURL_CA_BUNDLE

/* Location of default ca path */
#undef CURL_CA_PATH

/* to disable cookies support */
#undef CURL_DISABLE_COOKIES

/* to disable cryptographic authentication */
#undef CURL_DISABLE_CRYPTO_AUTH

/* to disable DICT */
#undef CURL_DISABLE_DICT

/* to disable FILE */
#undef CURL_DISABLE_FILE

/* to disable FTP */
#undef CURL_DISABLE_FTP

/* to disable Gopher */
#undef CURL_DISABLE_GOPHER

/* to disable HTTP */
#undef CURL_DISABLE_HTTP

/* to disable IMAP */
#undef CURL_DISABLE_IMAP

/* to disable LDAP */
#undef CURL_DISABLE_LDAP

/* to disable LDAPS */
#undef CURL_DISABLE_LDAPS

/* to disable POP3 */
#undef CURL_DISABLE_POP3

/* to disable proxies */
#undef CURL_DISABLE_PROXY

/* to disable RTSP */
#undef CURL_DISABLE_RTSP

/* to disable SMTP */
#undef CURL_DISABLE_SMTP

/* to disable TELNET */
#undef CURL_DISABLE_TELNET

/* to disable TFTP */
#undef CURL_DISABLE_TFTP

/* to disable TLS-SRP authentication */
#undef CURL_DISABLE_TLS_SRP

/* to disable verbose strings */
#undef CURL_DISABLE_VERBOSE_STRINGS

/* to make a symbol visible */
#undef CURL_EXTERN_SYMBOL

/* to enable hidden symbols */
#undef CURL_HIDDEN_SYMBOLS

/* Use Windows LDAP implementation */
#undef CURL_LDAP_WIN

/* when not building a shared library */
#undef CURL_STATICLIB

/* your Entropy Gathering Daemon socket pathname */
#undef EGD_SOCKET

/* Define if you want to enable IPv6 support */
#undef ENABLE_IPV6

/* Define to the type qualifier of arg 1 for getnameinfo. */
#undef GETNAMEINFO_QUAL_ARG1

/* Define to the type of arg 1 for getnameinfo. */
#undef GETNAMEINFO_TYPE_ARG1

/* Define to the type of arg 2 for getnameinfo. */
#undef GETNAMEINFO_TYPE_ARG2

/* Define to the type of args 4 and 6 for getnameinfo. */
#undef GETNAMEINFO_TYPE_ARG46

/* Define to the type of arg 7 for getnameinfo. */
#undef GETNAMEINFO_TYPE_ARG7

/* Specifies the number of arguments to getservbyport_r */
#undef GETSERVBYPORT_R_ARGS

/* Specifies the size of the buffer to pass to getservbyport_r */
#undef GETSERVBYPORT_R_BUFSIZE

/* Define to 1 if you have the alarm function. */
#undef HAVE_ALARM

/* Define to 1 if you have the <alloca.h> header file. */
#undef HAVE_ALLOCA_H

/* Define to 1 if you have the <arpa/inet.h> header file. */
#undef HAVE_ARPA_INET_H

/* Define to 1 if you have the <arpa/tftp.h> header file. */
#undef HAVE_ARPA_TFTP_H

/* Define to 1 if you have the <assert.h> header file. */
#undef HAVE_ASSERT_H

/* Define to 1 if you have the basename function. */
#undef HAVE_BASENAME

/* Define to 1 if bool is an available type. */
#undef HAVE_BOOL_T

/* Define to 1 if you have the clock_gettime function and monotonic timer. */
#undef HAVE_CLOCK_GETTIME_MONOTONIC

/* Define to 1 if you have the closesocket function. */
#undef HAVE_CLOSESOCKET

/* Define to 1 if you have the CloseSocket camel case function. */
#undef HAVE_CLOSESOCKET_CAMEL

/* Define to 1 if you have the connect function. */
#undef HAVE_CONNECT

/* Define to 1 if you have the `CRYPTO_cleanup_all_ex_data' function. */
#undef HAVE_CRYPTO_CLEANUP_ALL_EX_DATA

/* Define to 1 if you have the <crypto.h> header file. */
#undef HAVE_CRYPTO_H

/* Define to 1 if you have the <des.h> header file. */
#undef HAVE_DES_H

/* Define to 1 if you have the <dlfcn.h> header file. */
#undef HAVE_DLFCN_H

/* Define to 1 if you have the `ENGINE_cleanup' function. */
#undef HAVE_ENGINE_CLEANUP

/* Define to 1 if you have the `ENGINE_load_builtin_engines' function. */
#undef HAVE_ENGINE_LOAD_BUILTIN_ENGINES

/* Define to 1 if you have the <errno.h> header file. */
#undef HAVE_ERRNO_H

/* Define to 1 if you have the <err.h> header file. */
#undef HAVE_ERR_H

/* Define to 1 if you have the fcntl function. */
#undef HAVE_FCNTL

/* Define to 1 if you have the <fcntl.h> header file. */
#undef HAVE_FCNTL_H

/* Define to 1 if you have a working fcntl O_NONBLOCK function. */
#undef HAVE_FCNTL_O_NONBLOCK

/* Define to 1 if you have the fdopen function. */
#undef HAVE_FDOPEN

/* Define to 1 if you have the `fork' function. */
#undef HAVE_FORK

/* Define to 1 if you have the freeaddrinfo function. */
#undef HAVE_FREEADDRINFO

/* Define to 1 if you have the freeifaddrs function. */
#undef HAVE_FREEIFADDRS

/* Define to 1 if you have the fsetxattr function. */
#undef HAVE_FSETXATTR

/* fsetxattr() takes 5 args */
#undef HAVE_FSETXATTR_5

/* fsetxattr() takes 6 args */
#undef HAVE_FSETXATTR_6

/* Define to 1 if you have the ftruncate function. */
#undef HAVE_FTRUNCATE

/* Define to 1 if you have the gai_strerror function. */
#undef HAVE_GAI_STRERROR

/* Define to 1 if you have a working getaddrinfo function. */
#undef HAVE_GETADDRINFO

/* Define to 1 if the getaddrinfo function is threadsafe. */
#undef HAVE_GETADDRINFO_THREADSAFE

/* Define to 1 if you have the `geteuid' function. */
#undef HAVE_GETEUID

/* Define to 1 if you have the gethostbyaddr function. */
#undef HAVE_GETHOSTBYADDR

/* Define to 1 if you have the gethostbyaddr_r function. */
#undef HAVE_GETHOSTBYADDR_R

/* gethostbyaddr_r() takes 5 args */
#undef HAVE_GETHOSTBYADDR_R_5

/* gethostbyaddr_r() takes 7 args */
#undef HAVE_GETHOSTBYADDR_R_7

/* gethostbyaddr_r() takes 8 args */
#undef HAVE_GETHOSTBYADDR_R_8

/* Define to 1 if you have the gethostbyname function. */
#undef HAVE_GETHOSTBYNAME

/* Define to 1 if you have the gethostbyname_r function. */
#undef HAVE_GETHOSTBYNAME_R

/* gethostbyname_r() takes 3 args */
#undef HAVE_GETHOSTBYNAME_R_3

/* gethostbyname_r() takes 5 args */
#undef HAVE_GETHOSTBYNAME_R_5

/* gethostbyname_r() takes 6 args */
#undef HAVE_GETHOSTBYNAME_R_6

/* Define to 1 if you have the gethostname function. */
#undef HAVE_GETHOSTNAME

/* Define to 1 if you have a working getifaddrs function. */
#undef HAVE_GETIFADDRS

/* Define to 1 if you have the getnameinfo function. */
#undef HAVE_GETNAMEINFO

/* Define to 1 if you have the `getpass_r' function. */
#undef HAVE_GETPASS_R

/* Define to 1 if you have the `getppid' function. */
#undef HAVE_GETPPID

/* Define to 1 if you have the `getprotobyname' function. */
#undef HAVE_GETPROTOBYNAME

/* Define to 1 if you have the `getpwuid' function. */
#undef HAVE_GETPWUID

/* Define to 1 if you have the `getrlimit' function. */
#undef HAVE_GETRLIMIT

/* Define to 1 if you have the getservbyport_r function. */
#undef HAVE_GETSERVBYPORT_R

/* Define to 1 if you have the `gettimeofday' function. */
#undef HAVE_GETTIMEOFDAY

/* Define to 1 if you have a working glibc-style strerror_r function. */
#undef HAVE_GLIBC_STRERROR_R

/* Define to 1 if you have a working gmtime_r function. */
#undef HAVE_GMTIME_R

/* if you have the function gnutls_srp_verifier */
#undef HAVE_GNUTLS_SRP

/* if you have the gssapi libraries */
#undef HAVE_GSSAPI

/* Define to 1 if you have the <gssapi/gssapi_generic.h> header file. */
#undef HAVE_GSSAPI_GSSAPI_GENERIC_H

/* Define to 1 if you have the <gssapi/gssapi.h> header file. */
#undef HAVE_GSSAPI_GSSAPI_H

/* Define to 1 if you have the <gssapi/gssapi_krb5.h> header file. */
#undef HAVE_GSSAPI_GSSAPI_KRB5_H

/* if you have the GNU gssapi libraries */
#undef HAVE_GSSGNU

/* if you have the Heimdal gssapi libraries */
#undef HAVE_GSSHEIMDAL

/* if you have the MIT gssapi libraries */
#undef HAVE_GSSMIT

/* Define to 1 if you have the `idna_strerror' function. */
#undef HAVE_IDNA_STRERROR

/* Define to 1 if you have the `idn_free' function. */
#undef HAVE_IDN_FREE

/* Define to 1 if you have the <idn-free.h> header file. */
#undef HAVE_IDN_FREE_H

/* Define to 1 if you have the <ifaddrs.h> header file. */
#undef HAVE_IFADDRS_H

/* Define to 1 if you have the `inet_addr' function. */
#undef HAVE_INET_ADDR

/* Define to 1 if you have the inet_ntoa_r function. */
#undef HAVE_INET_NTOA_R

/* inet_ntoa_r() takes 2 args */
#undef HAVE_INET_NTOA_R_2

/* inet_ntoa_r() takes 3 args */
#undef HAVE_INET_NTOA_R_3

/* Define to 1 if you have a IPv6 capable working inet_ntop function. */
#undef HAVE_INET_NTOP

/* Define to 1 if you have a IPv6 capable working inet_pton function. */
#undef HAVE_INET_PTON

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the ioctl function. */
#undef HAVE_IOCTL

/* Define to 1 if you have the ioctlsocket function. */
#undef HAVE_IOCTLSOCKET

/* Define to 1 if you have the IoctlSocket camel case function. */
#undef HAVE_IOCTLSOCKET_CAMEL

/* Define to 1 if you have a working IoctlSocket camel case FIONBIO function.
   */
#undef HAVE_IOCTLSOCKET_CAMEL_FIONBIO

/* Define to 1 if you have a working ioctlsocket FIONBIO function. */
#undef HAVE_IOCTLSOCKET_FIONBIO

/* Define to 1 if you have a working ioctl FIONBIO function. */
#undef HAVE_IOCTL_FIONBIO

/* Define to 1 if you have a working ioctl SIOCGIFADDR function. */
#undef HAVE_IOCTL_SIOCGIFADDR

/* Define to 1 if you have the <io.h> header file. */
#undef HAVE_IO_H

/* if you have the Kerberos4 libraries (including -ldes) */
#undef HAVE_KRB4

/* Define to 1 if you have the `krb_get_our_ip_for_realm' function. */
#undef HAVE_KRB_GET_OUR_IP_FOR_REALM

/* Define to 1 if you have the <krb.h> header file. */
#undef HAVE_KRB_H

/* Define to 1 if you have the lber.h header file. */
#undef HAVE_LBER_H

/* Define to 1 if you have the ldapssl.h header file. */
#undef HAVE_LDAPSSL_H

/* Define to 1 if you have the ldap.h header file. */
#undef HAVE_LDAP_H

/* Define to 1 if you have the `ldap_init_fd' function. */
#undef HAVE_LDAP_INIT_FD

/* Use LDAPS implementation */
#undef HAVE_LDAP_SSL

/* Define to 1 if you have the ldap_ssl.h header file. */
#undef HAVE_LDAP_SSL_H

/* Define to 1 if you have the `ldap_url_parse' function. */
#undef HAVE_LDAP_URL_PARSE

/* Define to 1 if you have the `gcrypt' library (-lgcrypt). */
#undef HAVE_LIBGCRYPT

/* Define to 1 if you have the <libgen.h> header file. */
#undef HAVE_LIBGEN_H

/* Define to 1 if you have the `idn' library (-lidn). */
#undef HAVE_LIBIDN

/* Define to 1 if you have the `resolv' library (-lresolv). */
#undef HAVE_LIBRESOLV

/* Define to 1 if you have the `resolve' library (-lresolve). */
#undef HAVE_LIBRESOLVE

/* Define to 1 if you have the <librtmp/rtmp.h> header file. */
#undef HAVE_LIBRTMP_RTMP_H

/* Define to 1 if you have the `ssh2' library (-lssh2). */
#define HAVE_LIBSSH2 1

/* Define to 1 if you have the `libssh2_exit' function. */
#define HAVE_LIBSSH2_EXIT 1

/* Define to 1 if you have the <libssh2.h> header file. */
#define HAVE_LIBSSH2_H 1

/* Define to 1 if you have the `libssh2_init' function. */
#define HAVE_LIBSSH2_INIT 1

/* Define to 1 if you have the `libssh2_scp_send64' function. */
#define HAVE_LIBSSH2_SCP_SEND64 1

/* Define to 1 if you have the `libssh2_session_handshake' function. */
#define HAVE_LIBSSH2_SESSION_HANDSHAKE 1

/* Define to 1 if you have the `libssh2_version' function. */
#define HAVE_LIBSSH2_VERSION 1

/* Define to 1 if you have the `ssl' library (-lssl). */
#define HAVE_LIBSSL 1

/* if zlib is available */
#define HAVE_LIBZ 1

/* Define to 1 if you have the <limits.h> header file. */
#undef HAVE_LIMITS_H

/* if your compiler supports LL */
#undef HAVE_LL

/* Define to 1 if you have the <locale.h> header file. */
#undef HAVE_LOCALE_H

/* Define to 1 if you have a working localtime_r function. */
#undef HAVE_LOCALTIME_R

/* Define to 1 if the compiler supports the 'long long' data type. */
#undef HAVE_LONGLONG

/* Define to 1 if you have the malloc.h header file. */
#undef HAVE_MALLOC_H

/* Define to 1 if you have the memory.h header file. */
#undef HAVE_MEMORY_H

/* Define to 1 if you have the memrchr function or macro. */
#undef HAVE_MEMRCHR

/* Define to 1 if you have the MSG_NOSIGNAL flag. */
#undef HAVE_MSG_NOSIGNAL

/* Define to 1 if you have the <netdb.h> header file. */
#undef HAVE_NETDB_H

/* Define to 1 if you have the <netinet/in.h> header file. */
#undef HAVE_NETINET_IN_H

/* Define to 1 if you have the <netinet/tcp.h> header file. */
#undef HAVE_NETINET_TCP_H

/* Define to 1 if you have the <net/if.h> header file. */
#undef HAVE_NET_IF_H

/* Define to 1 if NI_WITHSCOPEID exists and works. */
#undef HAVE_NI_WITHSCOPEID

/* if you have an old MIT gssapi library, lacking GSS_C_NT_HOSTBASED_SERVICE
   */
#undef HAVE_OLD_GSSMIT

/* Define to 1 if you have the <openssl/crypto.h> header file. */
#undef HAVE_OPENSSL_CRYPTO_H

/* Define to 1 if you have the <openssl/engine.h> header file. */
#undef HAVE_OPENSSL_ENGINE_H

/* Define to 1 if you have the <openssl/err.h> header file. */
#undef HAVE_OPENSSL_ERR_H

/* Define to 1 if you have the <openssl/pem.h> header file. */
#undef HAVE_OPENSSL_PEM_H

/* Define to 1 if you have the <openssl/pkcs12.h> header file. */
#undef HAVE_OPENSSL_PKCS12_H

/* Define to 1 if you have the <openssl/rsa.h> header file. */
#undef HAVE_OPENSSL_RSA_H

/* Define to 1 if you have the <openssl/ssl.h> header file. */
#undef HAVE_OPENSSL_SSL_H

/* Define to 1 if you have the <openssl/x509.h> header file. */
#undef HAVE_OPENSSL_X509_H

/* Define to 1 if you have the <pem.h> header file. */
#undef HAVE_PEM_H

/* Define to 1 if you have the `perror' function. */
#undef HAVE_PERROR

/* Define to 1 if you have the `pipe' function. */
#undef HAVE_PIPE

/* if you have the function PK11_CreateGenericObject */
#undef HAVE_PK11_CREATEGENERICOBJECT

/* Define to 1 if you have a working poll function. */
#undef HAVE_POLL

/* If you have a fine poll */
#undef HAVE_POLL_FINE

/* Define to 1 if you have the <poll.h> header file. */
#undef HAVE_POLL_H

/* Define to 1 if you have a working POSIX-style strerror_r function. */
#undef HAVE_POSIX_STRERROR_R

/* if you have <pthread.h> */
#undef HAVE_PTHREAD_H

/* Define to 1 if you have the <pwd.h> header file. */
#undef HAVE_PWD_H

/* Define to 1 if you have the `RAND_egd' function. */
#undef HAVE_RAND_EGD

/* Define to 1 if you have the `RAND_screen' function. */
#undef HAVE_RAND_SCREEN

/* Define to 1 if you have the `RAND_status' function. */
#undef HAVE_RAND_STATUS

/* Define to 1 if you have the recv function. */
#undef HAVE_RECV

/* Define to 1 if you have the recvfrom function. */
#undef HAVE_RECVFROM

/* Define to 1 if you have the <rsa.h> header file. */
#undef HAVE_RSA_H

/* Define to 1 if you have the select function. */
#undef HAVE_SELECT

/* Define to 1 if you have the send function. */
#undef HAVE_SEND

/* Define to 1 if you have the <setjmp.h> header file. */
#undef HAVE_SETJMP_H

/* Define to 1 if you have the `setlocale' function. */
#undef HAVE_SETLOCALE

/* Define to 1 if you have the `setmode' function. */
#undef HAVE_SETMODE

/* Define to 1 if you have the `setrlimit' function. */
#undef HAVE_SETRLIMIT

/* Define to 1 if you have the setsockopt function. */
#undef HAVE_SETSOCKOPT

/* Define to 1 if you have a working setsockopt SO_NONBLOCK function. */
#undef HAVE_SETSOCKOPT_SO_NONBLOCK

/* Define to 1 if you have the <sgtty.h> header file. */
#undef HAVE_SGTTY_H

/* Define to 1 if you have the sigaction function. */
#undef HAVE_SIGACTION

/* Define to 1 if you have the siginterrupt function. */
#undef HAVE_SIGINTERRUPT

/* Define to 1 if you have the signal function. */
#undef HAVE_SIGNAL

/* Define to 1 if you have the <signal.h> header file. */
#undef HAVE_SIGNAL_H

/* Define to 1 if you have the sigsetjmp function or macro. */
#undef HAVE_SIGSETJMP

/* Define to 1 if sig_atomic_t is an available typedef. */
#undef HAVE_SIG_ATOMIC_T

/* Define to 1 if sig_atomic_t is already defined as volatile. */
#undef HAVE_SIG_ATOMIC_T_VOLATILE

/* Define to 1 if struct sockaddr_in6 has the sin6_scope_id member */
#undef HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID

/* Define to 1 if you have the socket function. */
#undef HAVE_SOCKET

/* Define to 1 if you have the <socket.h> header file. */
#undef HAVE_SOCKET_H

/* Define this if you have the SPNEGO library fbopenssl */
#undef HAVE_SPNEGO

/* if you have the function SRP_Calc_client_key */
#undef HAVE_SSLEAY_SRP

/* Define to 1 if you have the `SSL_get_shutdown' function. */
#undef HAVE_SSL_GET_SHUTDOWN

/* Define to 1 if you have the <ssl.h> header file. */
#undef HAVE_SSL_H

/* Define to 1 if you have the <stdbool.h> header file. */
#undef HAVE_STDBOOL_H

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H

/* Define to 1 if you have the <stdio.h> header file. */
#undef HAVE_STDIO_H

/* Define to 1 if you have the <stdlib.h> header file. */
#undef HAVE_STDLIB_H

/* Define to 1 if you have the strcasecmp function. */
#undef HAVE_STRCASECMP

/* Define to 1 if you have the strcasestr function. */
#undef HAVE_STRCASESTR

/* Define to 1 if you have the strcmpi function. */
#undef HAVE_STRCMPI

/* Define to 1 if you have the strdup function. */
#undef HAVE_STRDUP

/* Define to 1 if you have the strerror_r function. */
#undef HAVE_STRERROR_R

/* Define to 1 if you have the stricmp function. */
#undef HAVE_STRICMP

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#undef HAVE_STRING_H

/* Define to 1 if you have the strlcat function. */
#undef HAVE_STRLCAT

/* Define to 1 if you have the `strlcpy' function. */
#undef HAVE_STRLCPY

/* Define to 1 if you have the strncasecmp function. */
#undef HAVE_STRNCASECMP

/* Define to 1 if you have the strncmpi function. */
#undef HAVE_STRNCMPI

/* Define to 1 if you have the strnicmp function. */
#undef HAVE_STRNICMP

/* Define to 1 if you have the <stropts.h> header file. */
#undef HAVE_STROPTS_H

/* Define to 1 if you have the strstr function. */
#undef HAVE_STRSTR

/* Define to 1 if you have the strtok_r function. */
#undef HAVE_STRTOK_R

/* Define to 1 if you have the strtoll function. */
#undef HAVE_STRTOLL

/* if struct sockaddr_storage is defined */
#undef HAVE_STRUCT_SOCKADDR_STORAGE

/* Define to 1 if you have the timeval struct. */
#undef HAVE_STRUCT_TIMEVAL

/* Define to 1 if you have the <sys/filio.h> header file. */
#undef HAVE_SYS_FILIO_H

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#undef HAVE_SYS_IOCTL_H

/* Define to 1 if you have the <sys/param.h> header file. */
#undef HAVE_SYS_PARAM_H

/* Define to 1 if you have the <sys/poll.h> header file. */
#undef HAVE_SYS_POLL_H

/* Define to 1 if you have the <sys/resource.h> header file. */
#undef HAVE_SYS_RESOURCE_H

/* Define to 1 if you have the <sys/select.h> header file. */
#undef HAVE_SYS_SELECT_H

/* Define to 1 if you have the <sys/socket.h> header file. */
#undef HAVE_SYS_SOCKET_H

/* Define to 1 if you have the <sys/sockio.h> header file. */
#undef HAVE_SYS_SOCKIO_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/time.h> header file. */
#undef HAVE_SYS_TIME_H

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H

/* Define to 1 if you have the <sys/uio.h> header file. */
#undef HAVE_SYS_UIO_H

/* Define to 1 if you have the <sys/un.h> header file. */
#undef HAVE_SYS_UN_H

/* Define to 1 if you have the <sys/utime.h> header file. */
#undef HAVE_SYS_UTIME_H

/* Define to 1 if you have the <sys/xattr.h> header file. */
#undef HAVE_SYS_XATTR_H

/* Define to 1 if you have the <termios.h> header file. */
#undef HAVE_TERMIOS_H

/* Define to 1 if you have the <termio.h> header file. */
#undef HAVE_TERMIO_H

/* Define to 1 if you have the <time.h> header file. */
#undef HAVE_TIME_H

/* Define to 1 if you have the <tld.h> header file. */
#undef HAVE_TLD_H

/* Define to 1 if you have the `tld_strerror' function. */
#undef HAVE_TLD_STRERROR

/* Define to 1 if you have the `uname' function. */
#undef HAVE_UNAME

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to 1 if you have the `utime' function. */
#undef HAVE_UTIME

/* Define to 1 if you have the <utime.h> header file. */
#undef HAVE_UTIME_H

/* Define to 1 if compiler supports C99 variadic macro style. */
#undef HAVE_VARIADIC_MACROS_C99

/* Define to 1 if compiler supports old gcc variadic macro style. */
#undef HAVE_VARIADIC_MACROS_GCC

/* Define to 1 if you have the winber.h header file. */
#undef HAVE_WINBER_H

/* Define to 1 if you have the windows.h header file. */
#undef HAVE_WINDOWS_H

/* Define to 1 if you have the winldap.h header file. */
#undef HAVE_WINLDAP_H

/* Define to 1 if you have the winsock2.h header file. */
#undef HAVE_WINSOCK2_H

/* Define to 1 if you have the winsock.h header file. */
#undef HAVE_WINSOCK_H

/* Define this symbol if your OS supports changing the contents of argv */
#undef HAVE_WRITABLE_ARGV

/* Define to 1 if you have the writev function. */
#undef HAVE_WRITEV

/* Define to 1 if you have the ws2tcpip.h header file. */
#undef HAVE_WS2TCPIP_H

/* Define to 1 if you have the <x509.h> header file. */
#undef HAVE_X509_H

/* if you have the zlib.h header file */
#undef HAVE_ZLIB_H

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#undef LT_OBJDIR

/* Define to 1 if you are building a native Windows target. */
#undef NATIVE_WINDOWS

/* Define to 1 if you need the lber.h header file even with ldap.h */
#undef NEED_LBER_H

/* Define to 1 if you need the malloc.h header file even with stdlib.h */
#undef NEED_MALLOC_H

/* Define to 1 if you need the memory.h header file even with stdlib.h */
#undef NEED_MEMORY_H

/* Define to 1 if _REENTRANT preprocessor symbol must be defined. */
#undef NEED_REENTRANT

/* Define to 1 if _THREAD_SAFE preprocessor symbol must be defined. */
#undef NEED_THREAD_SAFE

/* cpu-machine-OS */
#undef OS

/* Name of package */
#undef PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the home page for this package. */
#undef PACKAGE_URL

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* a suitable file to read random data from */
#undef RANDOM_FILE

/* Define to the type qualifier pointed by arg 5 for recvfrom. */
#undef RECVFROM_QUAL_ARG5

/* Define to the type of arg 1 for recvfrom. */
#undef RECVFROM_TYPE_ARG1

/* Define to the type pointed by arg 2 for recvfrom. */
#undef RECVFROM_TYPE_ARG2

/* Define to 1 if the type pointed by arg 2 for recvfrom is void. */
#undef RECVFROM_TYPE_ARG2_IS_VOID

/* Define to the type of arg 3 for recvfrom. */
#undef RECVFROM_TYPE_ARG3

/* Define to the type of arg 4 for recvfrom. */
#undef RECVFROM_TYPE_ARG4

/* Define to the type pointed by arg 5 for recvfrom. */
#undef RECVFROM_TYPE_ARG5

/* Define to 1 if the type pointed by arg 5 for recvfrom is void. */
#undef RECVFROM_TYPE_ARG5_IS_VOID

/* Define to the type pointed by arg 6 for recvfrom. */
#undef RECVFROM_TYPE_ARG6

/* Define to 1 if the type pointed by arg 6 for recvfrom is void. */
#undef RECVFROM_TYPE_ARG6_IS_VOID

/* Define to the function return type for recvfrom. */
#undef RECVFROM_TYPE_RETV

/* Define to the type of arg 1 for recv. */
#undef RECV_TYPE_ARG1

/* Define to the type of arg 2 for recv. */
#undef RECV_TYPE_ARG2

/* Define to the type of arg 3 for recv. */
#undef RECV_TYPE_ARG3

/* Define to the type of arg 4 for recv. */
#undef RECV_TYPE_ARG4

/* Define to the function return type for recv. */
#undef RECV_TYPE_RETV

/* Define as the return type of signal handlers (`int' or `void'). */
#undef RETSIGTYPE

/* Define to the type qualifier of arg 5 for select. */
#undef SELECT_QUAL_ARG5

/* Define to the type of arg 1 for select. */
#undef SELECT_TYPE_ARG1

/* Define to the type of args 2, 3 and 4 for select. */
#undef SELECT_TYPE_ARG234

/* Define to the type of arg 5 for select. */
#undef SELECT_TYPE_ARG5

/* Define to the function return type for select. */
#undef SELECT_TYPE_RETV

/* Define to the type qualifier of arg 2 for send. */
#undef SEND_QUAL_ARG2

/* Define to the type of arg 1 for send. */
#undef SEND_TYPE_ARG1

/* Define to the type of arg 2 for send. */
#undef SEND_TYPE_ARG2

/* Define to the type of arg 3 for send. */
#undef SEND_TYPE_ARG3

/* Define to the type of arg 4 for send. */
#undef SEND_TYPE_ARG4

/* Define to the function return type for send. */
#undef SEND_TYPE_RETV

/* The size of `int', as computed by sizeof. */
#undef SIZEOF_INT

/* The size of `long', as computed by sizeof. */
#undef SIZEOF_LONG

/* The size of `off_t', as computed by sizeof. */
#undef SIZEOF_OFF_T

/* The size of `short', as computed by sizeof. */
#undef SIZEOF_SHORT

/* The size of `size_t', as computed by sizeof. */
#undef SIZEOF_SIZE_T

/* The size of `time_t', as computed by sizeof. */
#undef SIZEOF_TIME_T

/* The size of `void*', as computed by sizeof. */
#undef SIZEOF_VOIDP

/* Define to 1 if you have the ANSI C header files. */
#undef STDC_HEADERS

/* Define to the type of arg 3 for strerror_r. */
#undef STRERROR_R_TYPE_ARG3

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#undef TIME_WITH_SYS_TIME

/* Define to enable c-ares support */
#undef USE_ARES

/* if axTLS is enabled */
#undef USE_AXTLS

/* Define to disable non-blocking sockets. */
#undef USE_BLOCKING_SOCKETS

/* if CyaSSL is enabled */
#undef USE_CYASSL

/* if GnuTLS is enabled */
#undef USE_GNUTLS

/* if librtmp is in use */
#undef USE_LIBRTMP

/* if libSSH2 is in use */
#define USE_LIBSSH2 1

/* If you want to build curl with the built-in manual */
#undef USE_MANUAL

/* if NSS is enabled */
#undef USE_NSS

/* Use OpenLDAP-specific code */
#undef USE_OPENLDAP

/* if OpenSSL is in use */
#undef USE_OPENSSL

/* if PolarSSL is enabled */
#undef USE_POLARSSL

/* if SSL is enabled */
#undef USE_SSLEAY

/* if you want POSIX threaded DNS lookup */
#undef USE_THREADS_POSIX

/* Use TLS-SRP authentication */
#undef USE_TLS_SRP

/* Define to 1 if you are building a Windows target with large file support.
   */
#undef USE_WIN32_LARGE_FILES

/* Define to 1 if you are building a Windows target without large file
   support. */
#undef USE_WIN32_SMALL_FILES

/* to enable SSPI support */
#undef USE_WINDOWS_SSPI

/* Define to 1 if using yaSSL in OpenSSL compatibility mode. */
#undef USE_YASSLEMUL

/* Version number of package */
#undef VERSION

/* Define to avoid automatic inclusion of winsock.h */
#undef WIN32_LEAN_AND_MEAN

/* Define to 1 if OS is AIX. */
#ifndef _ALL_SOURCE
#  undef _ALL_SOURCE
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
#undef _FILE_OFFSET_BITS

/* Define for large files, on AIX-style hosts. */
#undef _LARGE_FILES

/* Define to empty if `const' does not conform to ANSI C. */
#undef const

/* Type to use in place of in_addr_t when system does not provide it. */
#undef in_addr_t

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#undef inline
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
#undef size_t

/* the signed version of size_t */
#undef ssize_t
