# The current state estimate (sent as a simple flat array and made into a column at the sensor node)
float64[] state

# The covariance of the state estimate (sent flat and reconstructed using reshape, since it always has as many rows and columns as state has elements/rows)
float64[] covar

