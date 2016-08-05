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

typedef NS_ENUM(NSInteger, NSGIFScale) {
    NSGIFScaleOptimize,
    NSGIFScaleVeryLow,
    NSGIFScaleLow,
    NSGIFScaleMedium,
    NSGIFScaleHigh,
    NSGIFScaleOriginal
};

typedef void (^ NSGIFProgressHandler)(double progress, NSUInteger offset, NSUInteger length, CMTime time, BOOL *__nullable stop, NSDictionary *__nullable frameProperties);

#pragma mark NSSerializedAssetRequest
@interface NSSerializedResourceRequest : NSObject
/* required.
 * a file's url of source video */
@property(nullable, nonatomic) NSURL * sourceVideoFile;

/* optional but important.
 * Defaults to NSGIFScaleOptimize (not set).
 * This option will affect gif file size, memory usage and processing speed. */
@property(nonatomic, assign) NSGIFScale scalePreset;

/* optional.
 * Defaults is to not set. unit is seconds, which means unlimited */
@property(nonatomic, assign) NSTimeInterval maxDuration;

/* optional but important.
 * Defaults to 4.
 * number of frames in seconds.
 * This option will affect gif file size, memory usage and processing speed. */
@property(nonatomic, assign) NSUInteger framesPerSecond;

/* optional but defaults is recommended.
 * Defaults is to not set.
 * How far along the video track we want to move, in seconds. It will automatically assign from duration of video and framesPerSecond. */
@property(nonatomic, assign) NSUInteger frameCount;

/* optional.
 * Defaults is to not set.
 * This option will crop(via AspectFill Mode) fast while create each images. Their size will be automatically calculated.
 * ex)
 *  square  : aspectRatioToCrop = CGSizeMake(1,1)
 *  16:9    : aspectRatioToCrop = CGSizeMake(16,9) */
@property(nonatomic, assign) CGSize aspectRatioToCrop;

/* optional.
 * Defaults is nil */
@property (nonatomic, copy, nullable) NSGIFProgressHandler progressHandler;

/* readonly
 * status for gif creating job 'YES' equals to 'now proceeding'
 */
@property(atomic, readonly) BOOL proceeding;

- (instancetype __nonnull)initWithSourceVideo:(NSURL * __nullable)fileURL;
+ (instancetype __nonnull)requestWithSourceVideo:(NSURL * __nullable)fileURL;
@end

#pragma mark NSGIFRequest
@interface NSGIFRequest : NSSerializedResourceRequest

/* optional.
 * defaults to nil.
 * automatically assign the file name of source video (ex: IMG_0000.MOV -> IMG_0000.gif)  */
@property(nullable, nonatomic) NSURL * destinationVideoFile;

/* optional.
 * Defaults to 0,
 * the number of times the GIF will repeat. which means repeat infinitely. */
@property(nonatomic, assign) NSUInteger loopCount;

/* optional.
 * Defaults to 0.13.
 * unit is 10ms, 1/100s, the amount of time for each frame in the GIF.
 * This option will NOT affect gif file size, memory usage and processing speed. It affect only FPS. */
@property(nonatomic, assign) CGFloat delayTime;

+ (NSGIFRequest * __nonnull)requestWithSourceVideo:(NSURL * __nullable)fileURL destination:(NSURL * __nullable)videoFileURL;
+ (NSGIFRequest * __nonnull)requestWithSourceVideoForLivePhoto:(NSURL *__nullable)fileURL;
@end

#pragma mark NSExtractFramesRequest
@interface NSFrameExtractingRequest : NSSerializedResourceRequest
/* optional.
 * Defaults to jpg.
 * This property will be affect to UTType(Automatically detected) of extracting image file.
 */
@property(nonatomic, readwrite, nullable) NSString * extension;

/* optional.
 * defaults to temp directory.
 */
@property(nullable, nonatomic) NSURL * destinationDirectory;
@end

@interface NSGIF : NSObject

+ (void)create:(NSGIFRequest *__nullable)request completion:(void (^ __nullable)(NSURL * __nullable))completionBlock;

+ (void)extract:(NSFrameExtractingRequest *__nullable)request completion:(void (^ __nullable)(NSArray<NSURL *> * __nullable))completionBlock;
@end
