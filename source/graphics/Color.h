///////////////////////////////////////////////////////////////////////////////
//
// Name:		Color.h
// Author:		Rich Cross
// Contact:		rich@wildfiregames.com
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _COLOR_H
#define _COLOR_H

#include "Vector3D.h"
#include "Vector4D.h"
#include "lib/types.h"

// simple defines for 3 and 4 component floating point colors - just map to
// corresponding vector types
typedef CVector3D RGBColor;
typedef CVector4D RGBAColor;

// SColor3ub: structure for packed RGB colors
struct SColor3ub
{
	u8 R;
	u8 G;
	u8 B;
};

// SColor4ub: structure for packed RGBA colors
struct SColor4ub
{
	u8 R;
	u8 G;
	u8 B;
	u8 A;

	SColor4ub() { }
	SColor4ub(u8 _r, u8 _g, u8 _b, u8 _a) : R(_r), G(_g), B(_b), A(_a) { }
};

// exposed as function pointer because it is set at init-time to
// one of several implementations depending on CPU caps.
extern u32 (*ConvertRGBColorTo4ub)(const RGBColor& src);

// call once ia32_init has run; detects CPU caps and activates the best
// possible codepath.
extern void ColorActivateFastImpl();


#endif
