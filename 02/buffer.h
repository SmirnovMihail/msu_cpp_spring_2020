class Buffer
{
    char* string;
    int len;
    int busy;
    void extend();
public:
    Buffer(int len);
    void add_char(char c);
    void reset();
    char* get();
    ~Buffer();
};

