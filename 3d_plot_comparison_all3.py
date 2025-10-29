import matplotlib.pyplot as plt

# Matrix sizes (powers of 2)
n = [2, 4, 8, 16, 32, 64, 128]

# Replace these with your measured times
iterative_times = [0.001000, 0.004000, 0.014000, 0.090000, 0.702000, 5.701000, 62.906000] 
dnc_times       = [0.003000, 0.016000, 0.120000, 0.900000, 6.768000, 84.295000, 449.614000]
strassen_times  = [0.004000, 0.021000, 0.217000, 1.105000, 7.367000, 59.447000, 394.097000]

plt.figure(figsize=(10, 6))

plt.plot(n, iterative_times, color='red', marker='o', markersize=8, linewidth=2, label="Iterative")
plt.plot(n, dnc_times, color='blue', marker='s', markersize=8, linewidth=2, label="Divide & Conquer")
plt.plot(n, strassen_times, color='green', marker='^', markersize=8, linewidth=2, label="Strassen")

plt.title("Execution Time Comparison of Matrix Multiplication Algorithms", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Matrix Size (n × n)", fontsize=12, color='purple')
plt.ylabel("Execution Time (seconds)", fontsize=12, color='purple')

plt.xticks(n)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(fontsize=12)
plt.show()