
#include <random>
#include <iostream>
#include <cmath>
#include <sstream>

int main(int argc, char **argv) {
	// 擬似乱数生成器
	std::random_device rnd;
	auto seed = rnd();
	std::mt19937 mt(seed);
	std::uniform_real_distribution<> dist(0.0, 1.0);

	std::cout << "seed," << seed << std::endl;

	// 次元
	int n = 2;
	if (argc > 1) {
		std::stringstream ss;
		ss << argv[1];
		ss >> n;
	}

	std::cout << "dimension," << n << std::endl;

	std::cout << std::endl;

	auto gamma = std::tgamma(n / 2.0 + 1);
	auto pow2 = std::pow(2.0, n);
	for (int points = 1000; points <= 100000; points += 1000) {
		// points 回ランダムに点を打ち、球の内側に入った数を数える
		int hit = 0;
		for (int i = 0; i < points; ++i) {
			double d = 0.0;
			for (int i = 0; i < n; ++i) {
				auto v = dist(mt);
				d += v * v;
			}
			if (d <= 1) {
				++hit;
			}
		}

		// 円周率を求める
		auto res = std::pow(hit * pow2 * gamma / points, 2.0 / n);
		std::cout << points << "," << res << std::endl;
	}

	return 0;
}
