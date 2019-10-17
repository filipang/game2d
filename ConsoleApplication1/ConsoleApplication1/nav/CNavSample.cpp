#include "CNavSample.h"


const int map[5][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					     { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
					     { 0, 9, 1, 1, 8, 0, 0, 0, 1, 0 },
					     { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
					     { 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 } };


tov::tov( int s, int xx, int yy, int fx, int fy )
	: step( s ), x( xx ), y( yy )
{
	int dx = x > fx ? x - fx : fx - x;
	int dy = y > fy ? y - fy : fy - y;
	h = dx + dy;
}
bool operator < (const tov& a, const tov& b)
{
	return a.h > b.h;
}

pos::pos( int xx, int yy )
	: x( xx ), y( yy )
{
}

CNavSample::CNavSample() : w(10), h(5)
{
	runmap = new unsigned int*[h];
	for ( int i= 0 ; i < h ; i++ )
		runmap[i] = new unsigned int[w];
	flush();
}


CNavSample::~CNavSample()
{
}


void CNavSample::flush()
{
	for ( int i= 0 ; i < h ; i++ )
		memset ( runmap[i], 0xff, w * sizeof ( unsigned int ));
	priotov = std::priority_queue<tov>();
	path.clear();
}

bool CNavSample::isValidCell( int step, int x, int y )
{
	if ( step >= runmap[y][x] )
		return false;

	if ( map[y][x] == 1 )
		return false;
	if ( y == w - 1 )
		return false;
	if ( map[y + 1][x] != 1 )
		return false;

	return true;
}
void CNavSample::traversePolicy( tov& from, int fx, int fy )
{
	for ( int y = from.y -1 ; y <= from.y + 1 ; y++ )
		if ( y >= 0 && y < h )
			for (int x = from.x -1 ; x <= from.x + 1; x++)
				if ( x >= 0 && x < w )
					{
						if ( isValidCell ( from.step + 1, x, y ) )
						{ 
							priotov.push ( tov ( from.step + 1, x, y, fx, fy ) );
							runmap[y][x] = from.step + 1;
						}
					}
}
bool CNavSample::endPolicy(tov& from, int fx, int fy)
{
	return ( from.x == fx && from.y == fy );
}
void CNavSample::pathPolicy( int fx, int fy )
{
	pos cur = pos ( fx, fy );
	int curstep = runmap[cur.y][cur.x];
	path.push_back ( cur );

	while (true)
	{
		int x, y;
		bool bDoBreak = false;;
		for ( y = cur.y -1 ; y <= cur.y + 1 ; y++ )
		{
			if ( y >= 0 && y < h )
				for ( x = cur.x -1 ; x <= cur.x + 1; x++)
					if ( x >= 0 && x < w )
						if ( runmap[y][x] == curstep - 1 )
						{ bDoBreak = true; break; }
			if ( bDoBreak )
				break;
		}
		cur = pos ( x, y );
		curstep--;
		path.push_back ( cur );
		if ( curstep == 1 )
			break;
	}
	std::reverse(path.begin(),path.end()); 
}

void CNavSample::run()
{
	flush();

	int sx, sy;
	int fx, fy;
	for ( int y = 0 ; y < h ; y++ )
		for (int x = 0; x < w; x++)
		{
			if ( map[y][x] == 9 )
			 { sx = x; sy = y; }
			if ( map[y][x] == 8 )
			 { fx = x; fy = y; }
		}
	//----------------------------------


	tov a = tov ( 1, sx, sy, fx, fy );
	priotov.push ( a );
	runmap[sy][sx] = a.step;

	while (true)
	{
		if ( priotov.empty() )
			break;

		tov cur = priotov.top();
		priotov.pop();

		if ( endPolicy( cur, fx, fy ) )
		{
			pathPolicy( fx, fy );
			break;
		}

		traversePolicy( cur, fx, fy );
	}


	_getch();
}