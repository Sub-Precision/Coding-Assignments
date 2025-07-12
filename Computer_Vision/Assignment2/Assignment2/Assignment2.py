import numpy as np
import cv2
import math

# Load the grayscale image
image = cv2.imread('house.png', cv2.IMREAD_GRAYSCALE)
height, width = image.shape

# Gaussian Kernel (5x5)
gaussian_kernel = np.array([
    [1, 4, 7, 4, 1],
    [4, 16, 26, 16, 4],
    [7, 26, 41, 26, 7],
    [4, 16, 26, 16, 4],
    [1, 4, 7, 4, 1]
]) / 273

# Sobel Kernels
Kx = np.array([
    [-1, 0, 1],
    [-2, 0, 2],
    [-1, 0, 1]
])

Ky = np.array([
    [-1, -2, -1],
    [0, 0, 0],
    [1, 2, 1]
])

# Helper function to perform convolution
def convolve(image, kernel):
    kernel_size = kernel.shape[0]
    pad = kernel_size // 2
    padded_image = np.pad(image, pad, mode='constant', constant_values=0)
    output = np.zeros_like(image, dtype=float)
    
    for i in range(height):
        for j in range(width):
            region = padded_image[i:i + kernel_size, j:j + kernel_size]
            output[i, j] = np.sum(region * kernel)
    
    return output

# Step 1: Apply Gaussian Smoothing
smoothed_image = convolve(image, gaussian_kernel)

# Step 2: Apply Sobel Kernels to find Gx and Gy
Gx = convolve(smoothed_image, Kx)
Gy = convolve(smoothed_image, Ky)

# Step 3: Compute the gradient magnitude
gradient_magnitude = np.sqrt(Gx**2 + Gy**2)
gradient_magnitude = (gradient_magnitude / gradient_magnitude.max() * 255).astype(np.uint8)

# Save the result
cv2.imwrite('house_edges.png', gradient_magnitude)

# Load the original image in grayscale
image = cv2.imread('photo.png', cv2.IMREAD_GRAYSCALE)

# Step 1: Apply a Low-Pass Filter (Gaussian Blur)
low_pass = cv2.GaussianBlur(image, (15, 15), 0)

# Step 2: Apply a High-Pass Filter
# Create a high-pass image by subtracting the low-pass image from the original
high_pass = cv2.subtract(image, low_pass)

# Step 3: Combine Low-Pass and High-Pass images to create a Hybrid Image
hybrid_image = cv2.add(low_pass, high_pass)

# Save and display results
cv2.imwrite('low_pass.png', low_pass)
cv2.imwrite('high_pass.png', high_pass)
cv2.imwrite('hybrid_image.png', hybrid_image)