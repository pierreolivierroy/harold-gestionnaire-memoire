class FirstFitManager : public IMemoryManager
{
    public:
    	virtual void initMem()
    	{
    		std::cout << "initMem\n";
    	}
        virtual void memAlloc()
        {
            //do stuff
            std::cout << "memAlloc\n";
        }
		virtual void freeMem(/*block*/)
		{
			std::cout << "freeMem\n";
		}
		virtual int getFreeBlockCount()
		{
			std::cout << "getFreeBlockCount\n";
			return 0;
		}
		virtual int getBlockCount()
		{
			std::cout << "getBlockCount\n";
			return 0;
		}
		virtual int getFreeMem()
		{
			std::cout << "getFreeMem\n";
			return 0;
		}
		virtual int getBiggestFreeBlock()
		{
			std::cout << "getBiggestFreeBlock\n";
			return 0;
		}
		virtual int getSmallFreeBlockCount(int)
		{
			std::cout << "getSmallFreeBlockCount\n";
			return 0;
		}
		virtual bool isMemAlloc()
		{
			std::cout << "isMemAlloc\n";
			return 0;
		}
};