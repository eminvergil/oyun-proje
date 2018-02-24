#include<math.h>
#include<algorithm>
class functions {
public:
	float sq(float n) {
		return n*n;
	}
	float dist(float x1,float y1, float x2, float y2) {
		return sqrt(sq(x2 - x1) + sq(y2 - y1));
	}
	float map(float value, float start1, float stop1, float start2, float stop2) {
		float outgoing =
			start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
		return outgoing;
	}
	float constrain(float amt, float low, float high) {
		return (amt < low) ? low : ((amt > high) ? high : amt);
	}
	bool rangeIntersect(float min0, float max0, float min1, float max1) {
		return fmax(min0,max0) >= fmin(min1,max1) && fmin(min0,max0) <= fmax(min1,max1);
	}
};