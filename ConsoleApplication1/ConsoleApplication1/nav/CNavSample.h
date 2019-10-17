#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>


struct tov
{
	int x, y;
	int h;
	int step;

	tov ( int s, int xx, int yy, int fx, int fy  );
};
bool operator < (const tov& a, const tov& b);

struct pos
{
	pos ( int xx, int yy );
	int x, y;
};


class CNavSample
{
private:
	int w, h;
	unsigned int **runmap;
	std::priority_queue<tov> priotov;
	std::vector<pos> path;

public:
	CNavSample();
	virtual ~CNavSample();

public:


	void flush();

	bool isValidCell( int step, int x, int y );
	void traversePolicy( tov& from, int fx, int fy );
	bool endPolicy( tov& from, int fx, int fy );
	void pathPolicy( int fx, int fy );

	void run();




};

