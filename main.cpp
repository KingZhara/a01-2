#include <iostream>
#include <vector>

struct RowCombination;

inline unsigned char GetStartingVal(
        unsigned char len,
        unsigned char depth
                                   ) noexcept;
inline unsigned char GetMaxVal(
        unsigned char len,
        unsigned char depth
                              ) noexcept;
inline void PrintMagicSquare(
        unsigned char len,
        unsigned long long val
                            ) noexcept;
void GenValidRowCombinations(
        unsigned char len,
        unsigned char depth,
        unsigned int row_val,
        unsigned int cur_val,
        RowCombination& cur_row,
        std::vector<RowCombination>& rowStorage
                                   ) noexcept;

int main()
{
    // The length of the square
    constexpr unsigned char length = 3;
    // UINT because (255*(1+255*255))/2 = 8290815
    constexpr unsigned int row_val = (length * (1 + (length * length))) / 2;



    return 0;
}

struct RowCombination
{
    unsigned char* row;

    explicit RowCombination(unsigned char len)
        : row(new unsigned char[len]) {}
};

void GenValidRowCombinations(
        unsigned char len,
        unsigned char depth,
        unsigned int row_val,
        unsigned int cur_val,
        RowCombination& cur_row,
        std::vector<RowCombination>& rowStorage
                            ) noexcept
{
    for (unsigned char i = GetStartingVal(len, depth); i < GetMaxVal(len, depth); i++)
    {
        GenValidRowCombinations(len, depth, row_val, cur_val, cur_row, rowStorage);
        // Handle row generation
    }
}

inline unsigned char GetStartingVal(
        unsigned char len,
        unsigned char depth
                                   ) noexcept
{
    if ((depth <= len / 2) || (len % 2 == 1 && depth == len / 2 + 1))
        return 0;
    else
        return (len % 2 == 1 ? (len * len) / 2 + 1 : (len * len) / 2);
}

inline unsigned char GetMaxVal(
        unsigned char len,
        unsigned char depth
                              ) noexcept
{
    if ((depth <= len / 2))
        return (len * len) / 2;
    else
        return len * len;
}

inline void PrintMagicSquare(unsigned char len, unsigned long long val) noexcept
{

}