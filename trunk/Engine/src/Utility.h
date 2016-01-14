#ifndef UTILITY_H
#define UTILITY_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <stdlib.h>
#include <stdio.h>

struct MvpMatrix
{
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
};
//const GLuint VALUE = 0xffffffff;

#define BUFFER_OFFSET(offset) ((void*)(NULL + offset))
#define ARRAY_ELEMENTS(a) ( sizeof(a)/sizeof(a[0]) )

template <class T>
int GetArrayLen(T& array)
{//使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度
	return (sizeof(array) / sizeof(array[0]));
}

static struct CloneFunc {
public:
	template <class _Pointer>
	_Pointer operator()(_Pointer p) const { return p->clone(); }
} clone_func;
static struct SafeDelete {
	template <class _Pointer> inline
	void operator()(_Pointer& ptr) {
		if (ptr) {
			delete ptr;
			ptr = NULL;
		}
	}

} safe_delete;

static struct SafeDeleteArray {
	template <class _Pointer> inline
	void operator()(_Pointer& ptr) {
		if (ptr) {
			delete[] ptr;
			ptr = NULL;
		}
	}
} safe_delete_array;

#endif