#ifndef MAPPOINT_HPP
#define MAPPOINT_HPP

class mapPoint
{
private:
	int					x;
	int					y;
	int					tile;
public:
	mapPoint(void);
	~mapPoint();
	mapPoint(const mapPoint &cpy);
	mapPoint& operator =(const mapPoint& other);
	int	getTile(void);
};

#endif
