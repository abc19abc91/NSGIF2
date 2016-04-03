//
//  NSGIF.h
//
//  Created by Sebastian Dobrincu
//  Modified by Brian Lee (github.com/metasmile)
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ImageIO/ImageIO.h>
#import <AVFoundation/AVFoundation.h>

#if TARGET_OS_IPHONE
#import <MobileCoreServices/MobileCoreServices.h>
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <CoreServices/CoreServices.h>
    #import <WebKit/WebKit.h>
#endif

@interface NSGIFRequest : NSObject

/* required. a file's url of source video */
@property(nullable, nonatomic) NSURL * sourceVideo;
/* optional. defaults to nil. automatically assign the file name of source video (ex: IMG_0000.MOV -> IMG_0000.gif)  */
@property(nullable, nonatomic) NSURL * destinationVideo;
/* optional. number of frames in seconds */
@property(nonatomic, assign) NSUInteger framesPerSecond;
/* optional. How far along the video track we want to move, in seconds. */
@property(nonatomic, assign) NSUInteger frameCount;
/* optional. Defaults to 0, the number of times the GIF will repeat. which means repeat infinitely. */
@property(nonatomic, assign) NSUInteger loopCount;
/* optional. unit is 10ms, 1/100s, the amount of time for each frame in the GIF */
@property(nonatomic, assign) CGFloat delayTime;
/* optional. defaults to 0, unit is seconds, which means unlimited */
@property(nonatomic, assign) NSTimeInterval maxVideoLength;

+ (NSGIFRequest * __nonnull)requestForOptimizedDefaults:(NSURL * __nullable)urlForSourceVideo destination:(NSURL * __nullable)videoFileURL;
+ (NSGIFRequest * __nonnull)requestForLivePhoto:(NSURL * __nullable)urlForSourceVideo destination:(NSURL * __nullable)videoFileURL;
@end

@interface NSGIF : NSObject

+ (void)optimalGIFfromURL:(NSGIFRequest * __nullable)request completion:(void(^ __nullable)(NSURL * __nullable GifURL))completionBlock;

+ (void)createGIFfromURL:(NSGIFRequest * __nullable)request completion:(void (^ __nullable)(NSURL * __nullable GifURL))completionBlock;
@end
