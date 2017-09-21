#pragma once

#include <cstdint>

/**

PTH VERSION 0 - Path files for Live for Speed S2
=============


The nodes are given by a fixed point position (X, Y, Z) and a
floating point direction (X, Y, Z)

The node can be considered as a line perpendicular to its direction.

Outer and driving area left and right limits are given.


TYPES :
=======

1) X,Y,Z int : 32-bit fixed point world coordinates (1 metre = 65536)

X and Y are ground coordinates, Z is up.

2) float : 32 bit floating point number


FILE DESCRIPTION :
==================

num   unit    offset  description
---   ----    ------  -----------

HEADER BLOCK :

6     char    0       LFSPTH              : do not read file if no match
1     byte    6       version             : 0 - do not read file if > 0
1     byte    7       revision            : 0 - do not read file if > 0
1     int     8       num nodes           : number
1     int     12      finish line         : number
......NODE BLOCKS


NODE BLOCK :

1     int     0       centre X            : fp
1     int     4       centre Y            : fp
1     int     8       centre Z            : fp
1     float   12      dir X               : float
1     float   16      dir Y               : float
1     float   20      dir Z               : float
1     float   24      limit left          : outer limit
1     float   28      limit right         : outer limit
1     float   32      drive left          : road limit
1     float   36      drive right         : road limit

*/

namespace LFS {

	//LFS PaTH File format
	namespace Format
	{
		//Describe PTH_HEADER_BLOCK
		struct PTH_HEADER
		{
			char LFSPTH[6];
			uint8_t version;
			uint8_t revision;
			int numberNodes;
			int finishLineIndex;
		};

		//Describe Center of Track
		struct NODE_CENTER
		{
			int x;
			int y;
			int z;
		};

		//Describe Direction of Track
		struct NODE_DIRECTION
		{
			float x;
			float y;
			float z;
		};

		//Describe Limits of Track
		struct NODE_LIMITS
		{
			float limitRight;
			float limitLeft;
		};

		//describe PTH_NODE_BLOCK
		struct PTH_NODE
		{
			NODE_CENTER center;
			NODE_DIRECTION direction;
			NODE_LIMITS limits;
			NODE_LIMITS drive;
		};

		//Describe PaTH
		struct PTH_FILE_FORMAT {
			PTH_HEADER header;
			PTH_NODE *nodes;
		};
	}

}