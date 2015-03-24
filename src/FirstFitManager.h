class FirstFitManager : public IMemoryManager
{
    public:
        virtual void memAlloc()
        {
            //do stuff
            std::cout << "memAlloc\n";
        }
};