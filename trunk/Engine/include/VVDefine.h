#ifndef _VISUAL_DEFINE_H_
#define _VISUAL_DEFINE_H_



#include "EngineHead.h"

#include <vector>
#include <glm/glm.hpp>
#include <assert.h>
#include <string>

#define SMALL_NUMBER		(0.1e-38f)
#define PLUS_MAX            (3.4e+38f)
#define PLUS_MIN            (-3.4e+38f)

#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076

#ifdef null 
#undef null 
#endif
#define null nullptr 

#ifdef autogenerate 
#undef autogenerate 
#endif
#define autogenerate = default

#ifdef nogenerate 
#undef nogenerate 
#endif
#define nogenerate = delete

#ifdef abstract 
#undef abstract 
#endif
#define abstract = 0

#ifdef interface 
#undef interface 
#endif
#define interface struct

#ifdef TypeCast 
#undef TypeCast 
#endif
#define TypeCast static_cast

#ifdef ConstCast 
#undef ConstCast 
#endif
#define ConstCast const_cast

#ifdef AddressCast 
#undef AddressCast 
#endif
#define AddressCast reinterpret_cast

#ifdef _MSC_VER

#ifdef not
#undef not
#endif
#define not !

#ifdef and
#undef and
#endif
#define and &&

#ifdef or
#undef or
#endif
#define or ||

#endif//_MSC_VER

#pragma warning(disable:4005)

#ifdef _WIN64
typedef unsigned long long __ptr;
#else
typedef long __ptr;
#endif

/** GL Buffers*/
enum GL_BUFFER_TYPE {
	kGL_BUFFER_TYPE_ARRAY = GL_ARRAY_BUFFER,
	kGL_BUFFER_TYPE_ELEMENT = GL_ELEMENT_ARRAY_BUFFER
};


enum GL_BUFFER_USAGE_HINT {
	kGL_BUFFER_USAGE_HINT_STATIC = GL_STATIC_DRAW,
	kGL_BUFFER_USAGE_HINT_DYNAMIC = GL_DYNAMIC_DRAW,

};
enum VerTexType {
	RM_P = 0,//顶点
	RM_P_N, // 顶点、法线
	RM_P_T,// 顶点、纹理
	RM_P_N_T,// 顶点、法线、纹理
	RM_P_C_T,
	RM_P_C,
	RM_P_N_C_T,
	RM_P_N_T_B,
	RM_P_N_T3,
	RM_ANY
};
enum RenderMode //顶点绘制的方式
{
	RM_POINTS = 0,
	RM_LINES,
	RM_LINE_LOOP,
	RM_LINE_STRIP,
	RM_TRIANGLES,
	RM_TRIANGLE_STRIP,
	RM_TRIANGLE_FAN,
};
enum DATA_TYPE {
	kDATA_TYPE_BYTE = GL_BYTE,
	kDATA_TYPE_UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
	kDATA_TYPE_FLOAT = GL_FLOAT,
	kDATA_TYPE_UINT = GL_UNSIGNED_INT,
	kDATA_TYPE_USHAORT = GL_UNSIGNED_INT
};
enum WC_INDEX{
	IN_ONT = 0,
	IN_TWO,
	IN_THREE,
	IN_FOUR,
	IN_EGE1,
	IN_EGE2,
	IN_EGE3,
	IN_EGE4,
	IN_ALL,
	IN_NULL
};

enum WC_DIR
{
	WC_FRONT = 0,
	WC_BACK,
	WC_LEFT,
	WC_RIGHT,
	WC_UP,
	WC_DOWN,
	WC_ALL,
	WC_NULL
};

enum TargetType //fbo的类型
{
	FBO_EMPTY = 0, //没有初始化的
	FBO_TCOLOR, //只有色彩纹理
	FBO_TDEPTH, //深度纹理
	FBO_TCOLOR_TDEPTH, //色彩与深度纹理
	FBO_TCOLOR_BDEPTH, //色彩纹理,深度buffer
	FBO_TDEPTHSTENCIL, //深度，模板纹理
	FBO_TCOLOR_BDEPTHSTENCIL, //色彩纹理，深度，模板 buffer
	FBO_TCOLOR_TDEPTHSTENCIL, //色彩纹理，深度，模板纹理
	FBO_CCOLOR_BDEPTH, //cube map 深度，专门为point light做阴影用的
};
enum ViewType {
	R_16_9 = 0, //16:9的显示模式
	R_3_2, //iphone
	R_4_3, //平板电脑的4:3
};
enum IntersectType
{
	IT_Outside,
	IT_Intersect,
	IT_Inside
};
enum HINT {
	HINT_FASTEST = GL_FASTEST,
	HINT_NICEST = GL_NICEST,
	HINT_DONT_CARET = GL_DONT_CARE
};

//定义绘制障碍模式
enum DRAW_TYPE{
	TM_LINES = 0,//线框
	TM_TRSLUCENCE,//半透明
	TM_LUCENCY,//不透明
	TM_NULL
};

enum Orientation {
	LandscaprLeft, //
	LandscapeRight, //
	Portrait//?
};
//灯光类型 directional, point, and spotlight
enum LightType {
	LT_POINT = 0,//点光
	LT_DIRECTION = 1,//
	LT_SPOTLIGHT = 2,
	LT_FORCE_DWORD = 0x7fffffff /* force 32-bit size enum */
};
enum LightModel{
	LT_STATIC = 0,//静态光
	LT_DYNAMIC = 1,//动态光
	LT_NULL
};

enum MartixMode{
	MM_MODEL = 0,
	MM_PROJECTION,
	MM_VIEW,
	MM_MODEL_VIEW_PROJECTION,
	MM_VIEW_PROJECTION,
	MM_MODEL_VIEW,
	MM_SIZE
};
enum COLOR_FORMAT{
	ECF_A1R5G5B5 = GL_UNSIGNED_SHORT_5_5_5_1,
	ECF_R5G6B5 = GL_UNSIGNED_SHORT_5_6_5,
	ECF_R4G4B4A4 = GL_UNSIGNED_SHORT_4_4_4_4,
	ECF_R8G8B8 = GL_UNSIGNED_BYTE,
	ECF_A8R8G8B8 = GL_UNSIGNED_INT,
	ECF_R16F,
	ECF_G16R16F,
	ECF_A16B16G16R16F,
	ECF_R32F,
	ECF_G32R32F,
	ECF_UNKNOWN
};
/** shader attribute index*/
enum {
	/** vertex attrib*/
	ATTRIB_VERTEX,
	/** texture 0 coord attrib*/
	ATTRIB_TEXTURE0,
	/** color attrib*/
	ATTRIB_COLOR,
	/** normal attrib*/
	ATTRIB_NORMAL,
	/** texture 1 coord attrib*/
	ATTRIB_TEXTURE1,
	/** texture 2 coord attrib*/
	//ATTRIB_TEXTURE2,
	/** bone index attrib*/
	ATTRIB_BONES_INDICES,
	/** bone weight attrib*/
	ATTRIB_BONES_WEIGHTS,
	/** attrib number*/
	NUM_ATTRIBUTES
};
//大小端平台定义
// short int s=0x1234;
// if (0x34==*((char *)&s)) printf("Little Endian\n");
// else printf("Big Endian\n");
#ifdef __BIG_ENDIAN__
///////////////////////////////////////////////////////////
inline void LITTLE_ENDIAN_WORD(void *pWord)
{
	unsigned char *pBytes = (unsigned char *)pWord;
	unsigned char temp;

	temp = pBytes[0];
	pBytes[0] = pBytes[1];
	pBytes[1] = temp;
}

inline void LITTLE_ENDIAN_DWORD(void *pWord)
{
	unsigned char *pBytes = (unsigned char *)pWord;
	unsigned char temp;

	// Swap outer bytes
	temp = pBytes[3];
	pBytes[3] = pBytes[0];
	pBytes[0] = temp;

	// Swap inner bytes
	temp = pBytes[1];
	pBytes[1] = pBytes[2];
	pBytes[2] = temp;
}
#else

// Define them away on little endian systems
#define LITTLE_ENDIAN_WORD 
#define LITTLE_ENDIAN_DWORD 
#endif

#define verifyMacroParticle() //return;



#endif