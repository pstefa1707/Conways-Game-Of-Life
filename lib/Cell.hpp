class Cell
{
    public:
        enum class Type {dead, alive};
        Cell(Type type)
        {
            _type = type;
        }
        void set_type(Type type);
        Type get_type();
    private:
        Type _type;
};