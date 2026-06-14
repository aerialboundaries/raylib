NAME        := a.out
CC          := gcc
CFLAGS      := -Wall -Wextra -std=c99 -pedantic-errors -MMD -MP


# 修正ポイント1: raylibに必要なリンクオプションを追加
LIBS        := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCDIR      := src
OBJDIR      := obj

# ソースファイルの取得

SRCS        := $(shell find $(SRCDIR) -name "*.c" -type f)
# オブジェクトファイルと依存関係ファイルのパスをobj/以下に変更
OBJS        := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS        := $(OBJS:.o=.d)

# デフォルトターゲット
.PHONY: all

all: $(NAME)

# リンク工程
# 修正ポイント2: リンク時に $(LIBS) を追加
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# コンパイル工程（ディレクトリ作成も同時に行う）
$(OBJDIR)/%.o: $(SRCDIR)/%.c

	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 依存関係ファイルの読み込み
-include $(DEPS)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: fclean

fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

# デバッグ用ターゲット
.PHONY: debug
debug: CFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: re

# 動作確認用
.PHONY: test
test: all
	./$(NAME)

.PHONY: run
run: all
	./$(NAME)
