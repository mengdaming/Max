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

#include <FLAC/metadata.h>

#import "AudioMetadata.h"

#ifdef __cplusplus
extern "C" {
#endif

// Types of audio contained in an Ogg stream that Max knows about
enum OggStreamType {
	kOggStreamTypeInvalid,
	kOggStreamTypeUnknown,
	kOggStreamTypeVorbis,
	kOggStreamTypeFLAC,
	kOggStreamTypeSpeex	
};
typedef enum OggStreamType OggStreamType;

	
// Get data directory (~/Application Support/Max/)
NSString * getApplicationDataDirectory(void);

// Create directory structure for path
void createDirectoryStructure(NSString *path);
	
// Remove /: characters and replace with _
NSString * makeStringSafeForFilename(NSString *string);

// Return a unique filename based on basename and extension
NSString * generateUniqueFilename(NSString *basename, 
								  NSString *extension);

// Create path if it does not exist; throw an exception if it exists and is a file
void validateAndCreateDirectory(NSString *path);

// Get an array of file types with built-in support
NSArray * getBuiltinExtensions(void);

// Get an array of file types supported by libsndfile
NSArray * getLibsndfileExtensions(void);

// Get an array of permissible file types
NSArray * getAudioExtensions(void);

// Get a timestamp in the ID3v2 format
NSString * getID3v2Timestamp(void);

// Add a Vorbis comment to a FLAC file
void addVorbisComment(FLAC__StreamMetadata		*block,
					  NSString					*key,
					  NSString					*value);

// Determine the type of audio contained in an ogg stream
OggStreamType oggStreamType(NSString *filename);

// Convert an NSImage to PNG data
NSData * getPNGDataForImage(NSImage *image);

// Convert an NSImage to JPG data
NSData * getJPGDataForImage(NSImage *image);

// Convert an NSImage to bitmapped data
NSData * getBitmapDataForImage(NSImage					*image,
							   NSBitmapImageFileType	type);
	
// Get an image representing the file's icon, scaled to size 
NSImage * getIconForFile(NSString	*filename,
						 NSSize		iconSize);

// Attempt to add the specified filename to the iTunes library, using metadata for the file's information
void addFileToiTunesLibrary(NSString		*filename, 
							AudioMetadata	*metadata);

// Create a temporary filename in directory with the given extension
NSString * generateTemporaryFilename(NSString *directory, 
									 NSString *extension);

// Returns YES if the file at pathname contains an embedded cue sheet
BOOL fileContainsEmbeddedCueSheet(NSString *pathname);
	
#ifdef __cplusplus
}
#endif
