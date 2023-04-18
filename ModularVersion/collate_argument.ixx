module;


export module collate_argument;

export namespace sqlite_orm {

    namespace internal {

        enum class collate_argument {
            binary,
            nocase,
            rtrim,
        };
    }

}
