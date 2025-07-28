import random
import time
from imppkg import harmonic_mean

numbers = [random.randint(1, 1000) for _ in range(1_000_000)]

start = time.perf_counter()
result = harmonic_mean.harmonic_mean(numbers)
end = time.perf_counter()

print(f"Result: {result}")
print(f"Elapsed time: {end - start:.6f} seconds")
