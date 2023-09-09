build: init
	@cmake --build /home/dingduck/Project/cl/dsaac/build --config Debug --target all --


init:
	@cmake --no-warn-unused-cli \
				-DCMAKE_BUILD_TYPE:STRING=Debug \
				-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
				-DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang \
				-DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ \
				-S/home/dingduck/Project/cl/dsaac \
				-B/home/dingduck/Project/cl/dsaac/build \
				-G Ninja

clean:
	@rm -rf build && echo cleanup all build files
