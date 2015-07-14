/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      CFPP-URL.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFURLRef wrapper
 */

#ifndef CFPP_URL_H
#define CFPP_URL_H

namespace CF
{
    class CFPP_EXPORT URL: public Type
    {
        public:
            
            typedef enum
            {
                PartAll                 = 0x00,
                PartFileSystemPath      = 0x01,
                PartFragment            = 0x02,
                PartHostName            = 0x03,
                PartLastPathComponent   = 0x04,
                PartNetLocation         = 0x05,
                PartParameterString     = 0x06,
                PartPassword            = 0x07,
                PartPath                = 0x08,
                PartPathExtension       = 0x09,
                PartQueryString         = 0x0A,
                PartResourceSpecifier   = 0x0B,
                PartScheme              = 0x0C,
                PartStrictPath          = 0x0D,
                PartUserName            = 0x0E
            }
            Part;
            
            typedef enum
            {
                PathStylePOSIX      = 0x00,
                PathStyleWindows    = 0x01
            }
            PathStyle;
            
            static URL FileSystemURL( std::string path, bool isDir = false );
            static URL FileSystemURL( const char * path, bool isDir = false );
            static URL FileSystemURL( CFTypeRef path, bool isDir = false );
            static URL FileSystemURL( CFStringRef path, bool isDir = false );
            
            URL( void );
            URL( const URL & value );
            URL( const AutoPointer & value );
            URL( CFTypeRef value );
            URL( CFURLRef value );
            URL( CFStringRef value );
            URL( std::string value );
            URL( const char * value );
            
            #ifdef CFPP_HAS_CPP11
            URL( URL && value );
            #endif
            
            virtual ~URL( void );
            
            URL & operator = ( URL value );
            URL & operator = ( const AutoPointer & value );
            URL & operator = ( CFTypeRef value );
            URL & operator = ( CFURLRef value );
            URL & operator = ( CFStringRef value );
            URL & operator = ( std::string value );
            URL & operator = ( const char * value );
            
            bool operator == ( const URL & value ) const;
            bool operator == ( CFTypeRef value ) const;
            bool operator == ( CFURLRef value ) const;
            bool operator == ( CFStringRef value ) const;
            bool operator == ( std::string value ) const;
            bool operator == ( const char * value ) const;
            
            bool operator != ( const URL & value ) const;
            bool operator != ( CFTypeRef value ) const;
            bool operator != ( CFURLRef value ) const;
            bool operator != ( CFStringRef value ) const;
            bool operator != ( std::string value ) const;
            bool operator != ( const char * value ) const;
            
            URL & operator /= ( CFStringRef value );
            URL & operator /= ( std::string value );
            URL & operator /= ( const char * value );
            
            std::string operator [] ( Part part ) const;
            
            operator std::string () const;
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            String GetFileSystemPath( PathStyle style = PathStylePOSIX ) const;
            String GetFragment( void ) const;
            String GetHostName( void ) const;
            String GetLastPathComponent( void ) const;
            String GetNetLocation( void ) const;
            String GetParameterString( void ) const;
            String GetPassword( void ) const;
            String GetPath( void ) const;
            String GetPathExtension( void ) const;
            String GetQueryString( void ) const;
            String GetResourceSpecifier( void ) const;
            String GetScheme( void ) const;
            String GetStrictPath( void ) const;
            String GetUserName( void ) const;
            Number GetPortNumber( void ) const;
            bool   HasDirectoryPath( void ) const;
            void   AppendPathComponent( CFStringRef component, bool isDirectory = false );
            void   AppendPathComponent( std::string component, bool isDirectory = false );
            void   AppendPathComponent( const char * component, bool isDirectory = false );
            void   AppendPathExtension( CFStringRef extension );
            void   AppendPathExtension( std::string extension );
            void   AppendPathExtension( const char * extension );
            void   DeleteLastPathComponent( void );
            void   DeletePathExtension( void );
            
            friend void swap( URL & v1, URL & v2 );
            
        private:
            
            CFURLRef _cfObject;
    };
}

#endif /* CFPP_URL_H */
