function Navbar () {
    return(
        <header className="pt-6">
        <nav className="max-w-6x1 mx-auto  flex justify-between items-center px-8 py-5 bg-white/5 backdrop-blur-md border border-white/20 rounded-[10px] mx-6 mt-6 shadow-lg">
            <h2 className="text-5x1 font-semibold tracking-wide">Precious</h2>
            <ul className="flex gap-8 text-gray-300">
                <li className="hover:text-white transition-colors cursor-pointer">Home</li>
                <li className="hover:text-white transition-colors cursor-pointer">About</li>
                <li className="hover:text-white transition-colors cursor-pointer">Projects</li>
                <li  className="hover:text-white transition-colors cursor-pointer">Contact</li>
            </ul>
        </nav>
        </header>
    );
}
export default Navbar;