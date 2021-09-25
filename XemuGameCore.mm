//
//  XemuGameCore.mm
//  xemu
//
//  Created by Francesco Magoga on 22/09/2021.
//

#import "XemuGameCore.h"

@implementation XemuGameCore
- (instancetype)init
{
	(self = [super init]);
	
	//xemu = new xemu::Xemu();
	
	return self;
}

- (void)dealloc
{
	//delete xemu;
}

- (BOOL)loadFileAtPath:(NSString *)path error:(NSError **)error
{
	
	
	return true;
}

- (void)stopEmulation
{
	xemu.stop();

	[super stopEmulation];
}

- (void)resetEmulation
{
	xemu.reset();
}

- (void)executeFrame
{
	xemu.update();
}
# pragma mark - Video

- (OEGameCoreRendering)gameCoreRendering
{
	return OEGameCoreRenderingOpenGL2Video;
}

- (OEIntSize)bufferSize
{
	return OEIntSizeMake(800, 600);
}

- (OEIntSize)aspectSize
{
	return OEIntSizeMake(4, 3);
}

- (NSTimeInterval)frameInterval
{
	return 60;
}

# pragma mark - Audio

- (NSUInteger)channelCount
{
	return 2;			//TODO: is this right? It seems Xbox original has also sorround, see screenshots at https://github.com/Ernegien/XboxEepromEditor
}

- (double)audioSampleRate
{
	return 44100;		//TODO: is this right?
}
/*
- (id<OEAudioBuffer>)audioBufferAtIndex:(NSUInteger)index
{
	return self;
}

- (NSUInteger)read:(void *)buffer maxLength:(NSUInteger)len
{
	NativeMix((short *)buffer, (int)(len / (AUDIO_CHANNELS * sizeof(uint16_t))));
	return len;
}

- (NSUInteger)write:(const void *)buffer maxLength:(NSUInteger)length
{
	return 0;
}

- (NSUInteger)length
{
	return AUDIO_FREQ / 15;
}
*/
# pragma mark - Save States

- (void)saveStateToFileAtPath:(NSString *)fileName completionHandler:(void (^)(BOOL, NSError *))block
{
}

- (void)loadStateFromFileAtPath:(NSString *)fileName completionHandler:(void (^)(BOOL, NSError *))block
{
}

/*# pragma mark - Input

const int buttonMap[] = { CTRL_UP, CTRL_DOWN, CTRL_LEFT, CTRL_RIGHT, 0, 0, 0, 0, CTRL_TRIANGLE, CTRL_CIRCLE, CTRL_CROSS, CTRL_SQUARE, CTRL_LTRIGGER, CTRL_RTRIGGER, CTRL_START, CTRL_SELECT };

- (oneway void)didMovePSPJoystickDirection:(OEPSPButton)button withValue:(CGFloat)value forPlayer:(NSUInteger)player
{
	if(button == OEPSPAnalogUp || button == OEPSPAnalogDown)
		__CtrlSetAnalogY(button == OEPSPAnalogUp ? value : -value);
	else
		__CtrlSetAnalogX(button == OEPSPAnalogRight ? value : -value);
}

- (oneway void)didPushPSPButton:(OEPSPButton)button forPlayer:(NSUInteger)player
{
	__CtrlButtonDown(buttonMap[button]);
}

- (oneway void)didReleasePSPButton:(OEPSPButton)button forPlayer:(NSUInteger)player
{
	__CtrlButtonUp(buttonMap[button]);
}
*/
@end
