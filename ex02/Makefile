NAME            =   Form28B

CXX             =   c++
CXXFLAGS        =   -Wall -Werror -Wextra -std=c++98 -Iinclude -MMD -MP

BUILD_DIR       =   __build
SRC_DIR         =   src

SRC             =   src/AForm.cpp src/Bureaucrat.cpp src/main.cpp src/PresidentialPardonForm.cpp \
					src/RobotomyRequestForm.cpp src/ShrubberyCreationForm.cpp
OBJ             =   $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEP             =   $(OBJ:.o=.d)

RM              =   rm -rf

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
