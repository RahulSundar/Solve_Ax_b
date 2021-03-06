#include <vector>
class GPU_solver{
public:
    GPU_solver() = default;
    ~GPU_solver() = default;
    void run_cuda_gensolver(const int &n, const std::vector<double> &Aex,
            const std::vector<double> &bex);
    void run_cuda_symsolver(const int &n, const std::vector<double> &Aex,
            const std::vector<double> &bex);
    void deliver_result(std::vector<double> &x);
private:
    std::vector<double> h_A_;
    std::vector<double> h_b_;    
};
