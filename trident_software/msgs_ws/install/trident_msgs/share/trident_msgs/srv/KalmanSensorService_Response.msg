
# The calculated residual (is flat and made into a column in position node, like the state)
float32[] residual

# The kalman gain (reconstructed at destination, like covar. Should be reshaped with as many rows as there are residual elements, and as many columns as there are state elements (as far as i know))
float32[] gain

# The observation matrix, calculated using the Jacobian (reconstructed like gain, but reversed, with x rows and y columns)
float32[] observationmatrix
