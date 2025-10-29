import matplotlib.pyplot as plt

n_values = [10, 30, 40, 45]

dp_bottomup_times = [0.004000, 0.011000, 0.015000, 0.017000]

plt.figure(figsize=(6,4))
plt.plot(n_values, dp_bottomup_times, marker='d', color='purple', label="DP Bottom-Up")
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Fibonacci – Dynamic Programming (Bottom-Up) Time Complexity")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()