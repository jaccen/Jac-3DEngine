#include "Colour.h"


#if 1
Color::Color() : r(1.0f), g(1.0f), b(1.0f), a(1.0f) {
}


Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {
}


Color::Color(const Color& other) : r(other.r), g(other.g), b(other.b), a(other.a) {
}


Color::Color(const glm::vec4& other) : r(other.r), g(other.g), b(other.b), a(other.a) {
}

Color& Color::operator=(const Color& v) {
	r = v.r;
	g = v.g;
	b = v.b;
	a = v.a;
	return *this;
}


void Color::set(float r, float g, float b, float a) {
	x = r;
	y = g;
	z = b;
	w = a;
}


// void Color::set(const glm::vec3& rgb, float a) {
// 	x = rgb.r;
// 	y = rgb.g;
// 	z = rgb.b;
// 	w = a;
// }

int Color::getRGBA() const {
	return (int(r * 255.0f) << 24)
		| (int(g * 255.0f) << 16)
		| (int(b * 255.0f) << 8)
		| (int(a * 255.0f));
}


int Color::getARGB() const {
	return (int(a * 255.0f) << 24)
		| (int(r * 255.0f) << 16)
		| (int(g * 255.0f) << 8)
		| (int(b * 255.0f));
}



Color& Color::operator+=(const Color& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}


Color Color::operator+(const Color& other) const {
	Color tmp(*this);
	tmp += other;
	return tmp;
}



Color& Color::operator-=(const Color& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}


Color Color::operator-(const Color& other) const {
	Color tmp(*this);
	tmp -= other;
	return tmp;
}



Color& Color::operator*=(const Color& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
	return *this;
}


Color Color::operator*(const Color& other) const {
	Color tmp(*this);
	tmp *= other;
	return tmp;
}


Color& Color::operator*=(float value) {
	x *= value;
	y *= value;
	z *= value;
	w *= value;
	return *this;
}


Color Color::operator*(float value) const {
	Color tmp(*this);
	tmp *= value;
	return tmp;
}


Color operator*(float value, const Color& other) {
	return other * value;
}


Color& Color::operator/=(const Color& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
	return *this;
}


Color Color::operator/(const Color& other) const {
	Color tmp(*this);
	tmp /= other;
	return tmp;
}


Color& Color::operator/=(float value) {
	x /= value;
	y /= value;
	z /= value;
	w /= value;
	return *this;
}


Color Color::operator/(float value) const {
	Color tmp(*this);
	tmp /= value;
	return tmp;
}




bool Color::operator<(const Color& other) const {
	return x < other.x && y < other.y && z < other.z && w < other.w;
}


bool Color::operator>(const Color& other) const {
	return x > other.x && y > other.y && z > other.z && w > other.w;
}
const Color Color::black(0, 0, 0, 1);
const Color Color::zero(0, 0, 0, 0);
const Color Color::white(1.0f, 1.0f, 1.0f, 1.0f);
const Color Color::red(1.0f, 0.0f, 0.0f, 1.0f);
const Color Color::green(0.0f, 1.0f, 0.0f, 1.0f);
const Color Color::blue(0.0f, 0.0f, 1.0f, 1.0f);
const Color Color::yellow(1.0f, 1.0f, 0.0f, 1.0f);
const Color Color::lightSlateGray(0.464f, 0.531f, 0.597f, 1.0f);
const Color Color::cornflowerBlue(0.394f, 0.609f, 0.933f, 1.0f);
const Color Color::gray(0.742f, 0.742f, 0.742f, 1.0f);
const Color Color::purple(0.625f, 0.125f, 0.937f, 1.0f);
const Color Color::translucent(0.5f, 0.5f, 0.5f, 0.4f);
const Color Color::translucent2(0.625f, 0.125f, 0.937f, 0.7f);
const Color Color::fulltranslucent(0.5f, 0.5f, 0.5f, 1.0f);
#endif
