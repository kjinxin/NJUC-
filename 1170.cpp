#include <stdio.h>

struct _cTower
{
	int h,p;
};
int _geng[50001],_gcnt[50001],_ghigh[50001],_gn,_gts;
_cTower _glist[50001];
int main()
{
	scanf("%d", &_gn);
	for( int i = 0;i < _gn;++i )
	{
		scanf("%d%d", &_ghigh[i], &_geng[i]);
		int inp;
		for( inp = _gts;inp > 0 && _ghigh[i] > _glist[inp-1].h;--inp )
			_gcnt[i] += _geng[ _glist[inp-1].p ];
		_gts = inp+1;
		_glist[inp].h = _ghigh[i],_glist[inp].p = i;
		if( inp-1 >= 0 )
			_gcnt[ _glist[inp-1].p ] += _geng[i];
	}
	int max = 0;
	for( int i = 0;i < _gn;++i )
	{
		if( _gcnt[i] > max )
			max = _gcnt[i];
	}

	printf("%d\n", max);
	return 0;
}
