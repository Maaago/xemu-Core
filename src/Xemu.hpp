//
//  Xemu.hpp
//  xemu
//
//  Created by Francesco Magoga on 23/09/2021.
//

#ifndef Xemu_hpp
#define Xemu_hpp

namespace xemu
{
	class Xemu
	{
		public:
			Xemu();
			~Xemu();
		
			void start();
			void stop();
			void reset();
		
			void update();
	};
}

#endif /* Xemu_hpp */
