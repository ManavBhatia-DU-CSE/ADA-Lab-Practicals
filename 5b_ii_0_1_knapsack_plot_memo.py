import matplotlib.pyplot as plt

n_values = [10, 20, 30, 50, 100, 200]
avg_times = [0.000000, 0.000018, 0.000040, 0.000120, 0.000424, 0.001198]

plt.figure(figsize=(8,5))
plt.plot(n_values, avg_times, marker='o', color='blue', label='Memoization DP')

plt.title('0/1 Knapsack (Memoization) — Time Complexity Analysis')
plt.xlabel('Number of Items (n)')
plt.ylabel('Average Execution Time (seconds)')
plt.grid(True)
plt.legend()
plt.show()