#pragma once

#include "RealSenseTypes.generated.h"

// List of features provided by the RealSense SDK
enum RealSenseFeature : uint8 {
	CAMERA_STREAMING = 0x1,
	SCAN_3D = 0x2,
	HEAD_TRACKING = 0x4,
	SEGMENTATION_3D = 0x8,
	HAND_CURSOR = 0x16,
};

// Resolutions supported by the RealSense RGB camera
UENUM(BlueprintType) 
enum class EColorResolution : uint8 {
	UNDEFINED = 0 UMETA(DisplayName = " "),
	RES1 = 1 UMETA(DisplayName = "1920 x 1080 x 30"),
	RES2 = 2 UMETA(DisplayName = "1280 x 720 x 30"),
	RES3 = 3 UMETA(DisplayName = "640 x 480 x 60"),
	RES4 = 4 UMETA(DisplayName = "640 x 480 x 30"),
	RES5 = 5 UMETA(DisplayName = "320 x 240 x 60"),
	RES6 = 6 UMETA(DisplayName = "320 x 240 x 30"),
};

// Resolutions supported by the RealSense depth camera
// (F200) denotes that this resolution is only supported by the F200 camera.
// (R200) denotes that this resolution is only supported by the R200 camera.
UENUM(BlueprintType) 
enum class EDepthResolution : uint8 {
	UNDEFINED = 0 UMETA(DisplayName = " "),
	RES1 = 1 UMETA(DisplayName = "640 x 480 x 60 (F200)"),
	RES2 = 2 UMETA(DisplayName = "640 x 480 x 30 (F200)"),
	RES3 = 3 UMETA(DisplayName = "628 x 468 x 90 (R200)"),
	RES4 = 4 UMETA(DisplayName = "628 x 468 x 60 (R200)"),
	RES5 = 5 UMETA(DisplayName = "628 x 468 x 30 (R200)"),
	RES6 = 6 UMETA(DisplayName = "480 x 360 x 90 (R200)"),
	RES7 = 7 UMETA(DisplayName = "480 x 360 x 60 (R200)"),
	RES8 = 8 UMETA(DisplayName = "480 x 360 x 30 (R200)"),
	RES9 = 9 UMETA(DisplayName = "320 x 240 x 90 (R200)"),
	RES10 = 10 UMETA(DisplayName = "320 x 240 x 60 (R200)"),
	RES11 = 11 UMETA(DisplayName = "320 x 240 x 30 (R200)"),
};

// Resolutions supported by the RealSense SR300 camera in 3DSeg mode
UENUM(BlueprintType)
enum class E3DSegResolution : uint8 {
	UNDEFINED = 0 UMETA(DisplayName = " "),
	RES1 = 1 UMETA(DisplayName = "color:  640 x 360, depth: 640 x 480"),
	RES2 = 2 UMETA(DisplayName = "color:  960 x 540, depth: 640 x 480"),
	RES3 = 3 UMETA(DisplayName = "color: 1280 x 720, depth: 640 x 480"),
	RES4 = 4 UMETA(DisplayName = "color:  320 x 240, depth: 640 x 480"),
	RES5 = 5 UMETA(DisplayName = "color:  640 x 480, depth: 640 x 480"),
};

// RSSDK Pixel Format exposed to Blueprint (see pxcimage.h)
UENUM(BlueprintType) 
enum class ERealSensePixelFormat : uint8 {
	PIXEL_FORMAT_ANY = 0,  // Unknown/undefined
	COLOR_RGB32,    // BGRA layout
	DEPTH_G16_MM,   // 16-bit unsigned integer with precision mm.
};

// Supported RealSense camera models
UENUM(BlueprintType) 
enum class ECameraModel : uint8 {
	None = 0 UMETA(DisplayName = " "),
	F200 = 1 UMETA(DisplayName = "Front-Facing (F200)"),
	SR300 = 2 UMETA(DisplayName = "Short-Range (SR300)"),
	R200 = 3 UMETA(DisplayName = "World-Facing (R200)"),
	Other = 4 UMETA(DisplayName = "Unknown Camera Model")
};

// Supported modes for the 3D Scanning middleware
UENUM(BlueprintType) 
enum class EScan3DMode : uint8 {
	OBJECT = 0 UMETA(DisplayName = "Object"),
	FACE = 1 UMETA(DisplayName = "Face")
};

// File types supported by the 3D Scanning middleware for saving scans 
UENUM(BlueprintType) 
enum class EScan3DFileFormat : uint8 {
	OBJ = 0 UMETA(DisplayName = "OBJ")
};

// Basic 32-bit color structure (RGBA) 
USTRUCT(BlueprintType) 
struct FSimpleColor
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 R;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 G;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 B;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 A;
};

// Resolution of a RealSense camera stream
USTRUCT(BlueprintType) 
struct FStreamResolution
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fps;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERealSensePixelFormat format;
};

// The BodySideType enumerator itemizes the side of a hand cursor
UENUM(BlueprintType)
enum class EBodySideType : uint8 {
	BODY_SIDE_UNKNOWN = 0 UMETA(DisplayName = "The body side is unknown"),
	BODY_SIDE_LEFT = 1 UMETA(DisplayName = "The hand cursor is from a left hand"),
	BODY_SIDE_RIGHT = 2 UMETA(DisplayName = "The hand cursor is from a right hand"),
};

// The AlertType enumerator itemizes the alert events
UENUM(BlueprintType)
enum class EAlertType : uint8 {
	CURSOR_DETECTED = 1 UMETA(DisplayName = "A cursor is detected"),
	CURSOR_NOT_DETECTED = 2 UMETA(DisplayName = "A previous detected cursor is lost"),
	CURSOR_INSIDE_BORDERS = 3 UMETA(DisplayName = "The cursor is moved back to the tracking area"),
	CURSOR_OUT_OF_BORDERS = 4 UMETA(DisplayName = "The cursor is moved out of the tracking area"),
	CURSOR_TOO_CLOSE = 5 UMETA(DisplayName = "The cursor is too close to the camera"),
	CURSOR_TOO_FAR = 6 UMETA(DisplayName = "The cursor is too far away from the camera"),
	CURSOR_OUT_OF_LEFT_BORDER = 7 UMETA(DisplayName = "The cursor is touching the left tracking boundary"),
	CURSOR_OUT_OF_RIGHT_BORDER = 8 UMETA(DisplayName = "The cursor is touching the right tracking boundary"),
	CURSOR_OUT_OF_TOP_BORDER = 9 UMETA(DisplayName = "The cursor is touching the top tracking boundary"),
	CURSOR_OUT_OF_BOTTOM_BORDER = 10 UMETA(DisplayName = "The cursor is touching the bottom tracking boundary"),
	CURSOR_ENGAGED = 11 UMETA(DisplayName = "The cursor is ready to engage with the application"),
	CURSOR_DISENGAGED = 12 UMETA(DisplayName = "The cursor has left the screen bounds or disengaged"),
};
