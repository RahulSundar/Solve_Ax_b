#include <vector>
class GPU_solver{
public:
    GPU_solver() = default;
    ~GPU_solver() = default;
    void run_cusolver(const int &n, const int &m);
    void deliver_result(std::vector<double> &x);
private:
    std::vector<double> h_A_;
    std::vector<double> h_b_;    
};