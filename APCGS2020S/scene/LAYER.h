enum class LAYER
{
	BG,
	MAP,
	CHAR,
	UI,
	MAX,
};

LAYER begin(LAYER);
LAYER end(LAYER);
LAYER operator++(LAYER& key);
LAYER operator*(LAYER key);