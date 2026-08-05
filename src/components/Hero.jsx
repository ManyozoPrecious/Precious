function Hero() {
    return (
        <section className="max-w-4x1 mx-auto text-center py28 px6">
            <p className="text-blue-400 font-semibold text-lg">
                Hello I'm
            </p>
            <h1 className="text-6x1 md:text-8x1 font-black mt-4 tracking-tight">
                <span className="bg-gradient-to-r from-blue-400 via-cyan-300 to-white bg-clip-text text-transparent">
                Precious Manyozo
                </span>
            </h1>
            <h2 className="text-6x1 md:text-3x1 text-gray-300 mt-6">Computer Science Student & Aspiring software developer</h2>
            <p className="text-gray-400 mt-8 max-w-2x1 mx-auto leading-8">
                I enjoy building modern web applications, exploring new technologies, and and solving real world problems through code
            </p>
            <div className="flex justify-center gap-5 mt-10">
                <button className="bg-gradient-to-r from-blue-600  px-6 py-3 rounded-[4px] font-semibold transition-all duration-300 hover:scale-105 hover:shadow-lg hover:shadow-cyan-500/30">
                    View Projects
                </button>
                <button className="border border-gray-500 hover:border-white-700 px-6 py-3 rounded-[4px] font-semibold transition-all duration-300 hover:scale-105">
                    Contact Me
                </button>
            </div>
        </section>
    );

}
export default Hero;