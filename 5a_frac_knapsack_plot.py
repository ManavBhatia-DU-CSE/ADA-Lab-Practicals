import matplotlib.pyplot as plt

n_values = [10, 20, 30, 50, 100, 200]
greedy_times = [0.000001, 0.000002, 0.000005, 0.000012, 0.000044, 0.000156]

plt.plot(n_values, greedy_times, marker='o', label="Fractional Knapsack (Greedy)")
plt.xlabel("Number of items (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Time Complexity of Fractional Knapsack")
plt.legend()
plt.grid(True)
plt.show()