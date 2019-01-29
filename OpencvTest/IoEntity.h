#pragma once

namespace Icarus
{
	class IoEntity
	{
	private:
		bool _initialized;		

	protected:
		virtual void Init() = 0;
		virtual void Clean() = 0;
		
		void AssertInitialized();

	public:
		IoEntity();
		virtual ~IoEntity();

		bool IsInitialized();
		void Initialize();
		void Close();
	};
}
