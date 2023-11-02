namespace Config {
	bool roguelike_command = false;

	const int	key_left 		= 0;
	const int	key_right 		= 0;
	const int	key_forward		= 0;
	const int	key_backward	= 0;
	const int	key_rforward 	= 0;
	const int	key_lforward 	= 0;
	const int	key_rbackward	= 0;
	const int	key_lbackward	= 0;
	const int	key_back 		= 0;
	const int	key_set 		= 0;
}


void keyboard() {
	Config::key_set 		= 32;	// space

	if ( Config::roguelike_command ) {
		const int	Config::key_left 		= 104;	// h
		const int	Config::key_right 		= 108;	// l
		const int	Config::key_forward		= 107;	// k
		const int	Config::key_backward	= 106;	// j
		const int	Config::key_rforward 	= 117;	// u
		const int	Config::key_lforward 	= 121;	// y
		const int	Config::key_rbackward	= 110;	// n
		const int	Config::key_lbackward	= 98;	// b
		const int	Config::key_back 		= 27;	// escape
	}
	else if ( !Config::roguelike_command ) {
		const int	Config::key_left 		= 52;	// 4
		const int	Config::key_right 		= 54;	// 6
		const int	Config::key_forward		= 56;	// 8
		const int	Config::key_backward	= 50;	// 2
		const int	Config::key_rforward 	= 57;	// 9
		const int	Config::key_lforward 	= 55;	// 7
		const int	Config::key_rbackward	= 51;	// 3
		const int	Config::key_lbackward	= 49; 	// 1
		const int	Config::key_back 		= 27;	// escape
	}
}