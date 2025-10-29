import matplotlib.pyplot as plt

n_values = [10, 30, 40, 45]

dp_topdown_times = [0.009000, 0.035000, 0.063000, 0.068000]

plt.figure(figsize=(6,4))
plt.plot(n_values, dp_topdown_times, marker='^', color='green', label="DP Top-Down")
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Fibonacci – Dynamic Programming (Top-Down) Time Complexity")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()