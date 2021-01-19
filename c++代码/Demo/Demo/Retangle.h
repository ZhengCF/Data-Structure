class Point
{
public:
	Point();
	~Point();
	void set_x(int);
	void set_y(int);
	int get_x();
	int get_y();
private:
	int x;
	int y;
};

Point::Point()
{
	x = 0;
	y = 0;
}

Point::~Point()
{
}

void Point::set_x(int x1)
{
	x = x1;
}

void Point::set_y(int y1)
{
	y = y1;
}

int Point::get_x()
{
	return x;
}

int Point::get_y()
{
	return y;
}


class Retangle
{
public:
	Retangle();
	~Retangle();
	void set_p1(int x, int y);
	void set_p2(int x, int y);
	int get_area();
private:
	Point p1;
	Point p2;
};

Retangle::Retangle()
{
}

Retangle::~Retangle()
{
}

void Retangle::set_p1(int x, int y)
{
	p1.set_x(x);
	p1.set_y(y);
}

void Retangle::set_p2(int x, int y)
{
	p2.set_x(x);
	p2.set_y(y);
}

 int Retangle::get_area()
{
	unsigned int l_x, l_y;
	l_x = p1.get_x() - p2.get_x();
	l_y = p1.get_y() - p2.get_y();
	return l_x* l_y;
}
