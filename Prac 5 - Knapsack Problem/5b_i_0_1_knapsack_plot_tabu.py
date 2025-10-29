import matplotlib.pyplot as plt

n_values = [10, 20, 30, 50, 100, 200]
avg_times = [0.000004, 0.000012, 0.000020, 0.000044, 0.000170, 0.000412]

plt.figure(figsize=(8,5))
plt.plot(n_values, avg_times, marker='s', color='green', label='Tabulation DP')

plt.title('0/1 Knapsack (Tabulation) — Time Complexity Analysis')
plt.xlabel('Number of Items (n)')
plt.ylabel('Average Execution Time (seconds)')
plt.grid(True)
plt.legend()
plt.show()