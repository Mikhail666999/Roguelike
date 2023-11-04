namespace Config {
	bool roguelike_command	= false;

	enum class PublicKey {
		Back 		= 27,	// escape
		Set 		= '0', 	// '0'
	};

	enum class RoguelikeKey {
		Left 		= 'h',	// 'h'
		Right 		= 'l',	// 'l'
		Forward		= 'k',	// 'k'
		Backward	= 'j',	// 'j'
		RForward 	= 'u',	// 'u'
		LForward 	= 'y',	// 'y'
		RBackward	= 'n',	// 'n'
		LBackward	= 'b',	// 'b'
		
	};

	enum class KeypadKey {
		Left 		= 52,	// 4
		Right 		= 54,	// 6
		Forward		= 56,	// 8
		Backward	= 50,	// 2
		RForward 	= 57,	// 9
		LForward 	= 55,	// 7
		RBackward	= 51,	// 3
		LBackward	= 49,	// 1
	};
}

#define MAP_SIZE 				1024
#define MAP_PLACE_CHARACTERS 	0
#define MAP_PLACE_WALLS 		1
#define MAP_PLACE_ITEMS 		2
#define MAP_CHARACTERS_MAX 		2048