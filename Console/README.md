# Sample of .md syntaksis - this is Higer level

## Description - one level down

### Details of description - one more level down

### Bullet points

* Plain text bullet point
* [Home site link](http://arttam.co.uk)

> Tips and tricks
> Side notes marking

### Code extractions
* JavaScript <br>
```js
// MyComponent.js
import React from 'react';
import withViewport from './withViewport';

class MyComponent {
  render() {
      let { width, height } = this.props.viewport;
	  return <div>{`Viewport: ${width}x${height}`}</div>;
  }
}

export default withViewport(MyComponent);
```

* CPP <br>
```c++
// find_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

bool IsOdd (int i) {
	return ((i%2)==1);
}

int main () {
	std::vector<int> myvector;

	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(55);

	std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(), IsOdd);
	std::cout << "The first odd value is " << *it << '\n';

	return 0;
}
```



