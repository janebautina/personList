#pragma once

using namespace System;

// Conversion code from http://msdn.microsoft.com/en-us/library/1b4az623(v=vs.80).aspx
inline void MarshalString ( String ^ s, string& os ) {
   using namespace Runtime::InteropServices;
   const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}

// Conversion code from http://msdn.microsoft.com/en-us/library/1b4az623(v=vs.80).aspx
inline void MarshalString ( String ^ s, wstring& os ) {
   using namespace Runtime::InteropServices;
   const wchar_t* chars = 
      (const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}

// Remove leading/trailing whitespace from a string.
// From http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
inline std::string trim(const std::string& str,
    const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

// Convert Windows string to C++ string and remove leading/trailing whitespaces.
inline string trimWindowsString(String^ s) {
  string result;
  MarshalString(s, result);
  return trim(result);
}

/*
// Convert string to wide string: http://stackoverflow.com/questions/6691555/converting-narrow-string-to-wide-string
inline std::wstring toWideString( const std::string& as )
{
            // deal with trivial case of empty string
    if( as.empty() )    return std::wstring();

            // determine required length of new string
    size_t reqLength = ::MultiByteToWideChar( CP_UTF8, 0, as.c_str(), (int)as.length(), 0, 0 );

            // construct new string of required length
    std::wstring ret( reqLength, L'\0' );

            // convert old string to new string
    ::MultiByteToWideChar( CP_UTF8, 0, as.c_str(), (int)as.length(), &ret[0], (int)ret.length() );

            // return new string ( compiler should optimize this away )
    return ret;
}
*/

inline String^ toWindowsString(const string& s) {
  return gcnew String(s.c_str());
}

#undef _CRT_SECURE_NO_WARNINGS
