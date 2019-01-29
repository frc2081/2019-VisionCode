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

	public:
		IoEntity();
		virtual ~IoEntity();

		void Initialize();
		void Close();
	};
}
