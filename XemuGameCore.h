//
//  XemuGameCore.h
//  xemu
//
//  Created by Francesco Magoga on 22/09/2021.
//

#import <Cocoa/Cocoa.h>
#import <OpenEmuBase/OEGameCore.h>

#include "src/Xemu.hpp"

@class OERingBuffer;

OE_EXPORTED_CLASS
@interface XemuGameCore : OEGameCore
{
	xemu::Xemu xemu;
}
@end
