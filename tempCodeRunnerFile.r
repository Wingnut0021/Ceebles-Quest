set.seed(123)
n <- 100
data <- data.frame(
  age = sample(18:60, n, replace = TRUE),
  gender = sample(c("Male", "Female"), n, replace = TRUE),
  value = rnorm(n)
)

# Plotting using ggplot2
ggplot(data, aes(x = age, y = value, color = gender)) +
  geom_point() +
  labs(title = "Scatter plot of value by age, colored by gender",
       x = "Age",
       y = "Value",
       color = "Gender")