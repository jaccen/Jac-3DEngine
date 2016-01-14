#ifndef VISULA_COLOR_H
#define VISULA_COLOR_H

#include "VVDefine.h"



class Color{
public:
	union {
		struct {
			float x, y, z, w;
		};

		struct {
			float r, g, b, a;
		};
		float data[4];
	};

public:
	Color();
	Color(float r, float g, float b, float a);
	Color(const Color& other);
	Color(const glm::vec4& other);

	// vector plus
	Color& operator+=(const Color& other);
	Color operator+(const Color& other) const;


	// vector minus
	Color& operator-=(const Color& other);
	Color operator-(const Color& other) const;


	// vector multiplication
	Color& operator*=(const Color& other);
	Color operator*(const Color& other) const;
	Color& operator*=(float value);
	Color operator*(float value) const;

	// vector division
	Color& operator/=(const Color& other);
	Color operator/(const Color& other) const;
	Color& operator/=(float value);
	Color operator/(float value) const;


	bool operator<(const Color& other) const;
	bool operator>(const Color& other) const;

	Color& Color::operator=(const Color& v);
public:
	void set(float r, float g, float b, float a);
	template <class _InputValue>
	void set(_InputValue value);
	int getRGBA() const;
	int getARGB() const;


public:
	static const Color black;
	static const Color zero;
	static const Color white;
	static const Color red;
	static const Color green;
	static const Color blue;
	static const Color yellow;
	static const Color lightSlateGray;
	static const Color cornflowerBlue;
	static const Color gray;
	static const Color purple;
	static const Color translucent;
	static const Color translucent2;
	static const Color fulltranslucent;
};



#endif // !VISULA_COLOR_H
