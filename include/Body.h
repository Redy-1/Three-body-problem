#include "Engine.h"

class Body {
public:
	Body(double,double2,double2);
	~Body();

	double mass;
	double2 position;
	double2 velocity;

	void update_position();
	void update_velocity(Body&);
};