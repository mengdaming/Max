/*
 *  $Id$
 *
 *  Copyright (C) 2005 - 2007 Stephen F. Booth <me@sbooth.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#import <Cocoa/Cocoa.h>

#include <mac/All.h>
#include <mac/MACLib.h>
#include <mac/APECompress.h>

#import "Encoder.h"

using namespace APE;

enum {
	MAC_COMPRESSION_LEVEL_FAST			= 1,
	MAC_COMPRESSION_LEVEL_NORMAL		= 2,
	MAC_COMPRESSION_LEVEL_HIGH			= 3,
	MAC_COMPRESSION_LEVEL_EXTRA_HIGH	= 4,
	MAC_COMPRESSION_LEVEL_INSANE		= 5
};

@interface MonkeysAudioEncoder : Encoder
{
	IAPECompress			*_compressor;
	int						_compressionLevel;
	UInt32					_sourceBitsPerChannel;
	UInt32					_sourceBytesPerFrame;
}

@end
