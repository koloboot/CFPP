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
 * @header      CFPP-PropertyListType-Definition.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ base class for property list compatible types
 */

#ifndef CFPP_PROPERTY_LIST_TYPE_DEFINITION_H
#define CFPP_PROPERTY_LIST_TYPE_DEFINITION_H

namespace CF
{
    template < class T >
    T PropertyListType< T >::FromPropertyList( std::string path )
    {
        Data        data;
        URL         url;
        ReadStream  stream;
        AutoPointer ap;

        if( path.length() == 0 )
        {
            return static_cast< CFTypeRef >( NULL );
        }

        url = URL::FileSystemURL( path );
        
        if( stream.Open( url ) == false )
        {
            return static_cast< CFTypeRef >( NULL );
        }
        
        data = stream.Read();
        ap   = CFPropertyListCreateWithData( static_cast< CFAllocatorRef >( NULL ), data, 0, NULL, NULL );
        
        return ap.As< T >();
    }
    
    template < class T >
    T PropertyListType< T >::FromPropertyListString( std::string plist )
    {
        AutoPointer ap;
        Data        data;
        
        if( plist.length() == 0 )
        {
            return static_cast< CFTypeRef >( NULL );
        }
        
        data = CF::Data( plist );
        ap   = CFPropertyListCreateWithData( static_cast< CFAllocatorRef >( NULL ), data, 0, NULL, NULL );
        
        return ap.As< T >();
    }
    
    template < class T >
    bool PropertyListType< T >::ToPropertyList( std::string path, PropertyListFormat format ) const
    {
        URL         url;
        Data        d;
        WriteStream stream;
        
        if( this->IsValid() == false )
        {
            return false;
        }
        
        url = URL::FileSystemURL( path );
        d   = this->ToPropertyList( format );
        
        if( d.GetLength() == 0 )
        {
            return false;
        }
        
        if( stream.Open( url ) == false )
        {
            return false;
        }
        
        return stream.Write( d ) == d.GetLength();
    }
    
    template < class T >
    Data PropertyListType< T >::ToPropertyList( PropertyListFormat format ) const
    {
        AutoPointer          data;
        CFPropertyListFormat cfFormat;
        
        if( this->IsValid() == false )
        {
            return static_cast< CFDataRef >( NULL );
        }
        
        cfFormat = kCFPropertyListXMLFormat_v1_0;
        
        if( format == PropertyListFormatBinary )
        {
            cfFormat = kCFPropertyListBinaryFormat_v1_0;
        }
        
        data = CFPropertyListCreateData( static_cast< CFAllocatorRef >( NULL ), this->GetCFObject(), cfFormat, 0, NULL );
        
        return data.As< CFDataRef >();
    }
}

#endif /* CFPP_PROPERTY_LIST_TYPE_DEFINITION_H */
